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
    Path path = (ShortestPaths *)malloc(sizeof(ShortestPaths));
    path->noNodes = numVerticies(g);
    path->src = v;
    path->dist = malloc(path->noNodes*sizeof(int));
    path->pred = malloc(path->noNodes*sizeof(PredNode *));
    PQ queue = newPQ();

    
    for (int i = 0; i < path->noNodes; i++) {
        if (i != v) {
            path->dist[i] = 1000000;
            path->pred[i] = NULL;
        }
        else {
            path->dist[i] = 0;
            path->pred[i] = NULL;
        }
        ItemPQ new = makeItem(i, path->dist[i]);
        addPQ(queue, new);
    }

    while (!PQEmpty(queue)) {
        ItemPQ next = dequeuePQ(queue);
        AdjList hasEdge = outIncident(g, next.key);
        while (hasEdge != NULL) {
            if (path->dist[next.key] + hasEdge->weight < path->dist[hasEdge->w]) {
                path->dist[hasEdge->w] = path->dist[next.key] + hasEdge->weight;
                PredNode *previous = makePred(next.key, NULL);
                path->pred[next.key] = previous;
                ItemPQ new = makeItem(hasEdge->w, path->dist[hasEdge->w]);
                updatePQ(queue, new);

            }
            hasEdge = hasEdge->next;
        }
    }

    return *path;
}

void showShortestPaths(ShortestPaths paths) {

    printf("The shortest distance array for %d is:\n", paths.src);
    for (int i = 0; i < paths.noNodes; i++) {
        printf("%d: %d", i, paths.dist[i]);
    }
    printf("The previous node array for %d is:\n", paths.src);
    for (int i = 0; i < paths.noNodes; i++) {
        printf("%d: %p", i, paths.pred[i]);
    }

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
