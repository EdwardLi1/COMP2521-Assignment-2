// PQ ADT interface for Ass2 (COMP2521)
#include <stdbool.h>

typedef struct PQRep *PQ;

typedef struct ItemPQ {
   int         key;
   int         value;
} ItemPQ;

typedef struct QueueRep {
	ItemPQ *head;  // ptr to first node
	ItemPQ *tail;  // ptr to last node
	int size;
} QueueRep;


/* Creates new priority queue, that can store items of type ItemPQ.
*/
PQ newPQ(){
    PQ new = malloc(sizeof(PQ));
    if (new == NULL){
        printf("Malloc Failed");
        exit(1);
    }
    new->head = NULL;
    new->tail = NULL;
    new->size = 0;
    return new;
}

/* Adds item (ItemPQ) to the priority queue.
   If an item with 'key' exists, it's 'value' is updated.
*/
void  addPQ(PQ, ItemPQ){
void pq_insert(pq *p, pq_object *object, cost object_cost)
{
    ItemPQ *new = (ItemPQ *)malloc(sizeof(ItemPQ));
    if(new==NULL){
        printf("Malloc Failed\n");
        exit(1);
    }
    //empty queue case
    if (PQ->size == 0){
        
    }
    //1 element queue case
    PQ
      object->pq_cost=object_cost;
      new_item->content=object;

      new_item->next=p->next;
      p->next=new_item;
}

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
