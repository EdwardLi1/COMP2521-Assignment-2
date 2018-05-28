// PQ ADT interface for Ass2 (COMP2521)
#include "PQ.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define MAX_HEAPSIZE 100

typedef struct PQRep {
	ItemPQ *items
	int nslots;
	int size;
} PQRep;

void fixUp(Item a[], int i);
void swap(Item a[], int i, int j)

/* Creates new priority queue, that can store items of type ItemPQ.
*/
PQ newPQ(){
    PQ new = (PQRep *)malloc(sizeof(PQRep));
    if (new == NULL){
        printf("Malloc Failed");
        exit(1);
    }

    ItemPQ *newItems = MAX_HEAPSIZE*malloc(sizeof(ItemPQ));
    if (newItems == NULL){
        printf("Malloc Failed");
        exit(1);
    }
    new->items = newItems;
    new->size = 0;
    new->nslots = MAX_HEAPSIZE;
    return new;
}

int PQEmpty(PQ p) {
		return 0;
}

void  addPQ(PQ pq, ItemPQ, item){
    //check if item with key exists
    for(int i = 1; i <= pq->nslots; i++){
        if (pq->items[i]->key == item->key){
            pq->items[i]->value = item->value;
            break; 
        }
    }
    assert(pq->size < pq->nslots);
    pq->nitems++;
    pq->items[pq->nitems] = item;
    fixUp(pq->items, pq->size);
}

ItemPQ dequeuePQ(PQ pq) {
	ItemPQ throwAway = {0};
	return throwAway;
}

void updatePQ(PQ pq, ItemPQ element) {

}

void  showPQ(PQ pq) {

}

void  freePQ(PQ pq) {

}
//helper functions fixup and swap are taken from week11 lectures notes from COMP2521
void fixUp(PQItem a[], int i)
{
   while (i > 1 && less(a[i/2],a[i])) {
      swap(a, i, i/2);
      i = i/2;
   }
}
void swap(Item a[], int i, int j)
{
   Item tmp = a[i];
   a[i] = a[j];
   a[j] = tmp;
}
