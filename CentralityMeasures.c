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
	NodeValues betweeness;
	ShortestPaths path;
	int count1 = 0; //value for top of equation
	int count2 = 0; // value for bottom of equation
	betweeness.noNodes = numVerticies(g);
	int i = 0;
	while (i < betweeness.noNodes){//run through all nodes so that we find the betweeness centrality of each 
	    double value;
	    int j = 0;
	    while (j < betweeness.noNodes){//used to run dijkstra on all nodes and check which ones pass through i
	        path = dijkstra(g, j);
	        int k = 0;
	        while (path.pred[k] != NULL){//run through pred array with each value indicating a new shortest path
	            int l = 0;
	            while (path.pred[k][l].next != NULL){//run through the path to find if i exists in the path
	                if (path.pred[k][l].v == i){
	                    count2++;
	                }
	                count1++;
	                l++;
	            }
	            k++;
	        }
	        j++;
	    }
	    value = count1/count2;
	    betweeness.values[i] = value;      //betweeness of node i
	    i++;
	}
	return betweeness;
}

NodeValues betweennessCentralityNormalised(Graph g){
	NodeValues normalised;
	NodeValues betweeness  = betweennessCentrality(g);
	double bottom = (betweeness.noNodes-1)*(betweeness.noNodes-2);
	bottom = 1/bottom;
	int i = 0;
	double value = 0;
	while (i < betweeness.noNodes){
	    value = bottom * betweeness.values[i];
	    normalised.values[i] = value;
	    i++;
	}
	return normalised;
}

void showNodeValues(NodeValues values){

}

void freeNodeValues(NodeValues values){

}
