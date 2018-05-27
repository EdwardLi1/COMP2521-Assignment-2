// Graph ADT implementation for Ass2 (COMP2521)
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"

typedef struct GraphRep{
    int nV;
    int nE;
    adjListNode **edges;
} GraphRep;

Graph newGraph(int noNodes) {

    assert(noNodes != 0);
    Graph new = malloc(sizeof(GraphRep));
    new->nV = noNodes;
    new->nE = 0;
    new->edges = malloc(noNodes*sizeof(adjListNode *));
    for(int i = 0; i < noNodes; i++) {
        new->edges[i] = NULL;
    }
    return new;
}

void insertEdge(Graph g, Vertex src, Vertex dest, int weight) {

    assert(g != NULL && src >= 0 && src < g->nV);
    AdjList newEdge = malloc(sizeof(adjListNode));
    newEdge->w = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;
    AdjList cur = g->edges[src];

    if (cur == NULL) {
        cur = newEdge;
    }

    else {
        while (cur->next != NULL) {
            cur = cur->next;
        }
    }
    cur->next = newEdge;
    g->nE++;
}

void removeEdge(Graph g, Vertex src, Vertex dest) {
    AdjList cur = g->edges[src];

    //Edge is at start of list

    if (cur->w == dest) {
        g->edges[src] = cur->next;
        free(cur);
        return;
    }
    
    //Edge is in middle/at end
    
    while (cur->next != NULL) {
        if (cur->next->w == dest) {
            AdjList tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
            return;
        }
        cur = cur->next;
    }
}
bool adjacent(Graph g, Vertex src, Vertex dest) {

    int isAdjacent = 0;
    AdjList cur = g->edges[src];
    AdjList cur2 = g->edges[dest];

    while (cur != NULL && isAdjacent == 0) {
        if (cur->w == dest) {
            isAdjacent = 1;
        }
        cur = cur->next;
    }

    while (cur2 != NULL && isAdjacent == 0) {
        if (cur2->w == src) {
            isAdjacent = 2;
        }
        cur2 = cur2->next;
    }

    return isAdjacent;
}
int numVerticies(Graph g) {
    return g->nV;
}

//Returns a list of adjacent vertices on outgoing edges from a given vertex
AdjList outIncident(Graph g, Vertex v){
    return g->edges[v];
}

//Returns a list of adjacent vertices on incoming edges from a given vertex.
AdjList inIncident(Graph g, Vertex v){

    AdjList head = NULL;
    AdjList cur = NULL;

    for (int i = 0; i < g->nV; i++) {
        if (adjacent(g, i, v)) {
            //Make new adjListNode
            AdjList new = malloc(sizeof(adjListNode));
            new->w = i;
            new->weight = 0;
            new->next = NULL;
            if (head == NULL) {
                head = new;
                cur = new;
            }
            else {
               cur->next = new;
            }
        }
    }

    return head;

}
void showGraph(Graph g) {
    for (int i = 0; i < g->nV; i++) {
        AdjList cur = g->edges[i];
        printf("[%d] has an edge to [", i);
        while (cur != NULL) {
            printf("%d ", cur->w);
            cur = cur->next;
        }
        printf("\n");
    }
}

void freeGraph(Graph g){
    
    for (int i = 0; i < g->nV; i++) {
        AdjList cur = g->edges[i];
        while (cur != NULL) {
            AdjList tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(g);
}

