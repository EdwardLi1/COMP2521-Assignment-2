// Graph ADT interface for Ass2 (COMP2521)
#include "CentralityMeasures.h"
#include "Dijkstra.h"
#include "PQ.h"
#include <stdlib.h>
#include <stdio.h>

NodeValues outDegreeCentrality(Graph g){
	//NodeValues out;
	
	//return out;
	NodeValues throwAway = {0};
	return throwAway;
}
NodeValues inDegreeCentrality(Graph g){/*
	NodeValues result;
	AdjList in = inIncident(g);
	int i = 0;
	if (out == NULL){
	} else {
	    AdjList curr = out;
	    while (curr != NULL){
	        curr = curr->next;
	        i++;
	    }
	}
	//i hold the number of nodes in the list
	in->noNodes = i;
	for (int j = 0; j < i; j++){
	    result->values[j] = in->w;
	}
	return result*/
	NodeValues throwAway = {0};
	return throwAway;
}
NodeValues degreeCentrality(Graph g) {/*
	NodeValues degree;
	NodeValues in = inDegreeCentrality(g);
	NodeValues out = outDegreeCentrality(g);
	degree->noNodes = 1;
	degree->values = in->values + out->values;
	return degree;
	*/
	NodeValues throwAway = {0};
	return throwAway;
}

NodeValues closenessCentrality(Graph g){
	NodeValues throwAway = {0};
	return throwAway;
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
