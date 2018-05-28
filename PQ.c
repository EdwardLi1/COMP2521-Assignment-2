// PQ ADT interface for Ass2 (COMP2521)
#include <stdbool.h>
#define MAX_HEAPSIZE 100

typedef struct PQRep *PQ;

typedef struct ItemPQ {
   int         key;
   int         value;
} ItemPQ;

typedef struct PQueueRep {
	ItemPQ *items
	int nslots;
	int size;
} PQRep;
//the PQRep struct is based off the Heap struct from week 11 lecture notes from COMP2521

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

/* Adds item (ItemPQ) to the priority queue.
   If an item with 'key' exists, it's 'value' is updated.
*/
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

/* Removes and returns the item (ItemPQ) with smallest 'value'.
   For items with equal 'value', observes FIFO.
   Returns null if this queue is empty.
*/
ItemPQ  dequeuePQ(PQ){
}

/* Updates item with a given 'key' value, by updating that item's value to the given 'value'.
   If item with 'key' does not exist in the queue, no action is taken
*/
void  updatePQ(PQ, ItemPQ){
}

int PQEmpty(PQ){
}

void  showPQ(PQ){
}
void  freePQ(PQ){
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

