// Graph ADT implementation for Ass2 (COMP2521)
/*
typedef struct GraphRep *Graph;

// vertices are ints
typedef int Vertex;


typedef struct _adjListNode {
   Vertex         w;
   int         weight;
   struct _adjListNode *next;
} adjListNode;

typedef adjListNode* AdjList;

*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _graph{
    int nV;
    int nE;
    adjListNode **edges;
} graph;
Graph newGraph(int noNodes){
    Graph new = malloc(sizeof(Graph));
    new->nV = 0;
    new->nE = 0;
    new->edges = malloc(noNodes*sizeof(adjListNode *))
    for(int i = 0; i < noNodes, i++){
        new->edges[i] = NULL;
    }
    return new;
}
void  insertEdge(Graph g, Vertex src, Vertex dest, int weight){
    adjListNode *newEdge = malloc(sizeof(adjListNode));
    newEdge->w = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;
    int i = 0;
    while (g->edges[src][i]->next != NULL){
        i++;
    }
    g->edges[src][i]->next = newEdge;
}
void  removeEdge(Graph g, Vertex src, Vertex dest){
    //make src->next = dest->next
    //remove src->next
    int i = 0;
    adjListNode *toRemove = NULL;
    adjListNode *prev = NULL;
    while (g->edges[src][i]->next != NULL){
        if(g->edges[src][i]->next->w == dest){
            bln = 1;
            toRemove = g->edges[src][i]->next;
            prev = g->edges[src][i];
            break;
        }
        i++;
    }
    if (bln == 1){
        adjListNode *next = toRemove->next;
        prev->next = next;
        free(curr);
    } else {
        printf("error")
    }

}
bool  adjacent(Graph g, Vertex src, Vertex dest){

}
int  numVerticies(Graph g){
    return g->nV;
}
AdjList outIncident(Graph g, Vertex v){

} //Returns a list of adjacent vertices on outgoing edges from a given vertex
AdjList inIncident(Graph g, Vertex v){

} //Returns a list of adjacent verticeson incoming edges from a given vertex.
void  showGraph(Graph g){

}
void  freeGraph(Graph g){

}

