// Dijkstra ADT interface for Ass2 (COMP2521)
#include "Dijkstra.h"
#include "PQ.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct ShortestPaths *Path;
ItemPQ makeItem(int key, int value); 
PredNode *makePred(int v, struct PredNode *next);

ShortestPaths dijkstra(Graph g, Vertex v) {

    //Initialising ShortestPaths
    Path path = malloc(sizeof(ShortestPaths));

    path->noNodes = numVerticies(g);
    path->src = v;
    path->dist = malloc(path->noNodes*sizeof(int));
    path->pred = malloc(path->noNodes*sizeof(PredNode *));
    
    for (int i = 0; i < path->noNodes; i++) {
        path->dist[i] = 1000000;
        path->pred[i] = NULL;
    }

    path->dist[v] = 0;

    int visited[path->noNodes];
    for (int i = 0; i < path->noNodes; i++) {
        visited[i] = -1;
    }

    PQ queue = newPQ();
    ItemPQ new = makeItem(v, 1);
    addPQ(queue, new);

    while (!PQEmpty(queue)) {
        ItemPQ next = dequeuePQ(queue);
        PredNode *previous = makePred(next.key, NULL);
        if (visited[next.key] == -1) {
            AdjList hasEdge = outIncident(g, next.key);
            while (hasEdge != NULL) {
                if ((hasEdge->weight + path->dist[next.key]) < path->dist[hasEdge->w]) {
                    path->dist[hasEdge->w] = hasEdge->weight + path->dist[next.key];
                    path->pred[hasEdge->w] = previous;
                    ItemPQ new = makeItem(hasEdge->w, hasEdge->weight);
                    addPQ(queue,new);
                }
                hasEdge = hasEdge->next;
            }
        }
    } 
    
    return *path;
}

void showShortestPaths(ShortestPaths paths) {

}


void  freeShortestPaths(ShortestPaths paths) {

}

ItemPQ makeItem(int key, int value) {
    ItemPQ *new = malloc(sizeof(ItemPQ));
    new->key = key;
    new->value = value;
    return *new;
}

PredNode *makePred(int v, struct PredNode *next) {
    PredNode *new = malloc(sizeof(PredNode));
    new->v = v;
    new->next = next;
    return new;
}





