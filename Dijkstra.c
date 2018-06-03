// Dijkstra ADT interface for Ass2 (COMP2521)
#include "Dijkstra.h"
#include "PQ.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#define INFINITY 1000000

typedef struct ShortestPaths *Path;
ItemPQ makeItem(int key, int value); 
PredNode *makePred(int v, struct PredNode *next);
void showPred(PredNode *Pred); 

ShortestPaths dijkstra(Graph g, Vertex v) {

    //Initialising ShortestPaths
    Path path = (ShortestPaths *)malloc(sizeof(ShortestPaths));
    path->noNodes = numVerticies(g);
    path->src = v;
    path->dist = malloc(path->noNodes*sizeof(int));
    path->pred = malloc(path->noNodes*sizeof(PredNode *));
    PQ queue = newPQ();

    //Setting all initial distances from source node to all other nodes to be infinity except for distance to source node itself
    //Setting all pred to be NULL
    for (int i = 0; i < path->noNodes; i++) {
        if (i != v) {
            path->dist[i] = INFINITY;
            path->pred[i] = NULL;
        }
        else {
            path->dist[i] = 0;
            path->pred[i] = NULL;
        }
        //Adding all the nodes to PQ with their priority based on distance from source node (currently infinity)
        ItemPQ new = makeItem(i, path->dist[i]);
        addPQ(queue, new);
    }

    while (!PQEmpty(queue)) {
        ItemPQ next = dequeuePQ(queue);
        AdjList hasEdge = outIncident(g, next.key);
        //Cycle through all outward edges and compare dist(src,a) + dist(a,b) with current dist(src,b)
        while (hasEdge != NULL) {
            if (path->dist[next.key] + hasEdge->weight < path->dist[hasEdge->w]) {
                //Update dist(src,b)
                path->dist[hasEdge->w] = path->dist[next.key] + hasEdge->weight;
                PredNode *previous = makePred(next.key, path->pred[next.key]);
                path->pred[hasEdge->w] = previous;
                //Update the priority of vertex b
                ItemPQ new = makeItem(hasEdge->w, path->dist[hasEdge->w]);
                updatePQ(queue, new);

            }
            hasEdge = hasEdge->next;
        }
    }

    for (int i = 0; i < path->noNodes; i++) {
        if (path->dist[i] == INFINITY) {
            path->dist[i] = 0;
            path->pred[i] = NULL;
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
    /*
    ShortestPaths *path = &paths;
    for (int i = 0; i < path->noNodes; i++) {
        free(path->dist[i]);
        free(path->pred[i]);
    }
    free(paths);
    */
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

void showPred(PredNode *Pred) {
    while (Pred != NULL) {
        if (Pred->next == NULL) {
            printf("%d->NULL\n", Pred->v);
        }
        else {
            printf("%d->", Pred->v);
        }
        Pred = Pred->next;
    }
}
