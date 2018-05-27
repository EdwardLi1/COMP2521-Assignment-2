#ifndef GRAPH
	#define GRAPH
	#include "Graph.h"
#endif
#include "GraphVis.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

    //Test 1
    Graph g = newGraph(5);
    insertEdge(g,1,2,1);
    insertEdge(g,2,1,10);
    insertEdge(g,4,2,60);
    insertEdge(g,3,2,6);
    insertEdge(g,4,0,15);
    removeEdge(g,4,0);
    removeEdge(g,4,2);
    printf("Adjacent function returns %d\n", adjacent(g, 2, 3));
    printf("Adjacent function returns %d\n", adjacent(g, 0, 4));
    showGraph(g);

	// draws the graph
  graphVis(g, DEFAULT);
	return EXIT_SUCCESS;
}
