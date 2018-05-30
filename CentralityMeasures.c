// Graph ADT interface for Ass2 (COMP2521)
#include "CentralityMeasures.h"
#include "Dijkstra.h"
#include "PQ.h"
#include <stdlib.h>
#include <stdio.h>

NodeValues outDegreeCentrality(Graph g){
	NodeValues result;
	result.noNodes = numVerticies(g);
	Vertex i = 0;
	while (i < numVerticies(g)){
	    AdjList out = outIncident(g, i);
	    int j = 0;
	    AdjList curr = out;
	    while (curr != NULL){
	        j++;
	        curr = curr->next;
	    }
	    //j now holds the size of AdjList in 
	    //j is also the indegree of in
	    result.values[i] = j;
	    i++;
	}
	return result;
}
NodeValues inDegreeCentrality(Graph g){
	NodeValues result;
	result.noNodes = numVerticies(g);
	Vertex i = 0;
	while (i < numVerticies(g)){
	    AdjList in = inIncident(g, i);
	    int j = 0;
	    AdjList curr = in;
	    while (curr != NULL){
	        j++;
	        curr = curr->next;
	    }
	    //j now holds the size of AdjList in 
	    //j is also the indegree of in
	    result.values[i] = j;
	    i++;
	}
	return result;
}
NodeValues degreeCentrality(Graph g) {
	NodeValues degree;
	degree.noNodes = numVerticies(g);
    int i = 0;
    NodeValues in = inDegreeCentrality(g);
    NodeValues out = outDegreeCentrality(g);
    while (i < degree.noNodes){
        degree.values[i] = in.values[i]+out.values[i];
    }
	return degree;
}

NodeValues closenessCentrality(Graph g){
	NodeValues closeness;
	closeness.noNodes = numVerticies(g);
	int i = 0;
	while (i < closeness.noNodes){
	    int n;
	    int j = 0;
	    while (j < closeness.noNodes){
	        if (adjacent(g, i, j)){
	            n++;
	        }
	        j++;
	    }
	    double left = n-1/closeness.noNodes-1;     //this is the left hand side of the W.F formula
	    double right = n-1;
	    //sum of shortest from src to i = 0..size
	    j = 0;
	    int sum = 0;
	    ShortestPaths shortest = dijkstra(g, i);
	    while (j < closeness.noNodes){
	        if (adjacent(g, i, j)){
	            sum = sum + shortest.dist[j];
	        }
	        j++;
	    }
	    right = right/sum;
	    closeness.values[i] = left * right;
	    i++;
	}
	return closeness;
}

NodeValues betweennessCentrality(Graph g){
	NodeValues throwAway = {0};
	return throwAway;
}

NodeValues betweennessCentralityNormalised(Graph g){
	NodeValues throwAway = {0};
	return throwAway;
}

void showNodeValues(NodeValues values){

}

void freeNodeValues(NodeValues values){

}
