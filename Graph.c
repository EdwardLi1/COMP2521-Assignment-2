// Graph ADT implementation for Ass2 (COMP2521)
// Made by Cary and Edward
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"

typedef struct GraphRep{
    int nV;         //Number of vertices in the graph
    int nE;         //Number of edges in the graph
    adjListNode **edges;        //Adjacency list of edges
} GraphRep;

Graph newGraph(int noNodes) {
    assert(noNodes != 0);
    Graph new = malloc(sizeof(GraphRep));
    
    //Check if malloc failed
    if (new == NULL){
        printf("Malloc Failed");
        exit(1);
    } 
    
    //Initialise values
    new->nV = noNodes;
    new->nE = 0;
    new->edges = malloc(noNodes*sizeof(adjListNode *));
    
    //Check if malloc failed
    if (new->edges == NULL){
        printf("Malloc Failed");
        exit(1);
    } 
    for(int i = 0; i < noNodes; i++) {
        new->edges[i] = NULL;
    }
    
    return new;
}

void insertEdge(Graph g, Vertex src, Vertex dest, int weight) {
    //Check for valid inputs
    assert(g != NULL && src >= 0 && src < g->nV);
    AdjList newEdge = malloc(sizeof(adjListNode));
    
    //Add create the new edge
    newEdge->w = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;
    AdjList cur = g->edges[src];
    
    //Check if src has no edges
    if (cur == NULL) {
        g->edges[src] = newEdge;
    }
    //Scan until the end of src's list
    else {
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newEdge;
    }
    //Increment the number of edges in the graph
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

    //Check if there is an edge from src to dest
    while (cur != NULL && isAdjacent == 0) {
        if (cur->w == dest) {
            isAdjacent = 1;
        }
        cur = cur->next;
    }

    //Check if there is an edge from src to dest
    while (cur2 != NULL && isAdjacent == 0) {
        if (cur2->w == src) {
            isAdjacent = 1;
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

    //Create a new list to return
    AdjList head = NULL;
    AdjList tmp = NULL;
    
    //Iterate through every vertex to check if it has an edge to v
    for (int i = 0; i < g->nV; i++) {
        AdjList cur = g->edges[i];
        while (cur != NULL) {
            //If an edge exists create a new node and add it to our created list
            if (cur->w == v) {
                AdjList new = malloc(sizeof(adjListNode));
                new->w = i;
                new->weight = cur->weight;
                new->next = NULL;
                //empty list case
                if (head == NULL) {
                    head = new;
                    tmp = new;
                }
                else {
                    tmp->next = new;
                    tmp = tmp->next;
                }
            }
            cur = cur->next;
        }
    }

    return head;

}
void showGraph(Graph g) {
    
    //Print out all edges from each vertex in a line
    for (int i = 0; i < g->nV; i++) {
        AdjList cur = g->edges[i];
        //Initial statement
        printf("[%d] has an edge to [", i);
        while (cur != NULL) {
            //All edges 
            if (cur->next == NULL) {
                printf("%d", cur->w);
            }
            else {
                printf("%d, ", cur->w);
            }
            cur = cur->next;
        }
        printf("]\n");
    }
}

void freeGraph(Graph g){

    //Free each node of the list at a time
    for (int i = 0; i < g->nV; i++) {
        AdjList cur = g->edges[i];
        while (cur != NULL) {
            AdjList tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    //Free graph
    free(g);
}

