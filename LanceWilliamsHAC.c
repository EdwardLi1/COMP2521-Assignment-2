#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LanceWilliamsHAC.h"

static int max(int a, int b);

Dendrogram LanceWilliamsHAC(Graph g, int method){
    
    double dist = 0;                //denote infinity as -1
    int n = numVerticies(g);
    int array[n][n];
    int i = 0;
    int j = 0;
    while (i < n){
        while (j < n-i){        //we only need to look at the bottom part of the 2d array
            if (adjacent(g, i, j) || adjacent(g,j,i)){
                if (adjacent(g, i, j) && adjacent(g,j,i)){
                    //calculate dist with 1/max(dist(i,j),dist(j,i)))
                    dist = 1/max(g->edges[i][j].weight, edges[j][i].weight);        
                    //calculate dist with 1/max(dist(i,j),dist(j,i)))
                    array[j][j] = dist;
                }
                
            } else {  
                array[i][j] = -1;
                j++;
            }
        }
        
        i++;
    }
    Dendrogram dendrograms = (Dendrogram)malloc(n*sizeof(DNode));
    for (i = 1; i < n; i++;){
        dendrograms[i]->value = 1;
        dendrograms[i]->left = NULL;
        dendrograms[i]->right = NULL;
    }
    for (int k = 1, k < n; k++){
        //find closest 2 clusters
        //only need to consider bottom triangle of the 2d array
        dist = -1;
        for (i = 0; i < n; i++){
            for (j = 0; j < n-i; j++){
                
            }
        }
        
    }
    return dendrograms;
}


void freeDendrogram(Dendrogram d){
}

static int max(int a, int b){
    if (a > b){
        return a;
    } else {
        return b;
    }
}
