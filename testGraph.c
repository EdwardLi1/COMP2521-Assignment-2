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
    insertEdge(g,1,3,8);
    insertEdge(g,2,1,10);
    insertEdge(g,2,3,43);
    insertEdge(g,4,2,60);
    insertEdge(g,3,2,6);
    insertEdge(g,4,0,15);
    insertEdge(g,4,3,15);
    insertEdge(g,3,1,1);
    insertEdge(g,3,0,65);
    insertEdge(g,3,4,87);
    removeEdge(g,4,0);
    removeEdge(g,4,2);
    showGraph(g);

    printf("Adjacent function returns %d\n", adjacent(g, 2, 3));
    printf("Adjacent function returns %d\n", adjacent(g, 0, 4));

    AdjList out = outIncident(g, 3);
    printf("OutIncident returns a list with values:\n");
    while (out != NULL) {
        printf("%d ", out->w);
        out = out->next;
    }
    printf("\n");

    AdjList in = inIncident(g, 3);
    printf("inIncident for vertex 3 returns a list with values:\n");
    while (in != NULL) {
        printf("%d ", in->w);
        in = in->next;
    }
    printf("\n");

    AdjList in1 = inIncident(g, 4);
    printf("inIncident for vertex 4 returns a list with values:\n");
    while (in1 != NULL) {
        printf("%d ", in1->w);
        in1 = in1->next;
    }
    printf("\n");

    printf("The number of verticies in this graph is %d\n", numVerticies(g));
	// draws the graph
    
  graphVis(g, DEFAULT);
	return EXIT_SUCCESS;
}
