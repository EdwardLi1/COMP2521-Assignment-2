// PQ ADT interface for Ass2 (COMP2521)
#include "PQ.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#define INIT_HEAPSIZE 2

typedef struct PQRep {  //Heap implementation
	ItemPQ *items;
	int nslots;     //How many array indexes we have malloc'd
	int size;       //How many relevant array entries we have
} PQRep;

//helper function prototyes
static void fixUp(ItemPQ a[], int i);                                       //Restores priority after inserting an element at the end of the list
static void swap(ItemPQ a[], int i, int j);                                 //Swaps 2 items
static int larger(ItemPQ a, ItemPQ b);                                      //Checks if a is larger than b
static void fixDown(ItemPQ a[], int i, int N);                              //Restores priority after removing an element from the start of the list
static void arrayCopy(ItemPQ *array1, ItemPQ *array2, int size);            //Copies array1 into array2. Size is the size of array1

// Creates new priority queue, that can store items of type ItemPQ
PQ newPQ(){

    //Allocate space for a priority queue and check for malloc errors
    PQ new = malloc(sizeof(PQRep));
    if (new == NULL){
        printf("Malloc Failed");
        exit(1);
    }
    
    //Allocate space for a ItemPQ list and check for malloc errors
    ItemPQ *newItems = malloc(INIT_HEAPSIZE*sizeof(ItemPQ));
    if (newItems == NULL){
        printf("Malloc Failed");
        exit(1);
    }
    
    //Initialise values of a empty PQ
    new->items = newItems;
    new->size = 0; 
    new->nslots = INIT_HEAPSIZE;
    
    return new;
}

int PQEmpty(PQ p) {

    //Check if the size element is 0 or if the queue is NULL
	if (p->size == 0 || p == NULL){
	    return 1;
	}
	
	return 0;
}

void  addPQ(PQ pq, ItemPQ item){

    //Check if an item with key exists. If it does then update its value
    int bln = -1;
    for(int i = 1; i <= pq->size; i++){
        if (pq->items[i].key == item.key){
            updatePQ(pq, item);
            bln = 1;
            break; 
        }
    }
    
    //Check if we found an item with pre-existing key
    if (bln == -1){
        //Check if we have run out of memory in our ItemPQ list
        if (pq->size == pq->nslots -1){
            pq->nslots++;
            
            //Create a new list and check for malloc errors
            ItemPQ *newItems = malloc(pq->nslots*sizeof(ItemPQ));  
            if (newItems == NULL){
                printf("Malloc Failed");
                exit(1);
            }    
                  
            //Call helper function to copy original list into new one
            arrayCopy(pq->items, newItems, pq->size);
            free(pq->items);
            
            //Assign new list as the ItemPQ list for PQ
            pq->items = newItems;
        }
        
        //Insert new item
        assert(pq->size < pq->nslots);
        pq->size++;
        pq->items[pq->size] = item;
        
        //Fix the queue so that the parent's priority is always higher than its children
        fixUp(pq->items, pq->size);
    }
     
}

ItemPQ dequeuePQ(PQ pq) {

    //Remove the first item
    ItemPQ remove = pq->items[1];
    
    //Move last item to the front
    pq->items[1] = pq->items[pq->size];
    pq->size--;
    
    //Fix the queue so that the parent's priority is always higher than its children
    fixDown(pq->items, 1, pq->size);
    
	return remove;
}

void updatePQ(PQ pq, ItemPQ element) {

    int i = 0;
    //Iterate through the list and look for they key
    while (i <= pq->size){
        if (pq->items[i].key == element.key){
            pq->items[i].value = element.value;
            //Ensure that priority is maintained
            fixUp(pq->items, pq->size);
        }
        i++;
    }
}

void showPQ(PQ pq) {

    //Create a counter to detect powers of 2
    int i = 1;
    int j = 0;
    int count = 0;
    while (i < pq->nslots && i <= pq->size){
        double power = pow(2,j);
        
        //Print an item's key
        printf("%d ", pq->items[i].key);
        count++;
        
        //If we have printed 2 times the number of items than the previous line then print a new line
        if (count == power){
            printf("\n");
            count = 0;
            j++;
        }
        i++;
    }
    
    printf("\n");
    printf("\n");
    
    //Repeat as above but this time printing the item's value
    i = 1;
    j = 0;
    count = 0;
    while (i < pq->nslots && i <= pq->size){
        double power = pow(2,j);
        printf("%d ", pq->items[i].value);
        count++;
        if (count == power){
            printf("\n");
            count = 0;
            j++;
        }
        i++;
        
    }
    printf("\n");
}

void  freePQ(PQ pq){
    free(pq->items);
    free(pq);
}

//----------------------------------------------------------------------------------------------------------
//      HELPER FUNCTIONS
// Helper functions fixup, fix down and swap are based off week11 lectures notes from COMP2521. They are edited and adapted to fit our requirements
//----------------------------------------------------------------------------------------------------------


static void fixUp(ItemPQ a[], int i){

    //If a child is smaller than its parent then swap them
    while (i > 1 && larger(a[i/2],a[i]) == 1) {
        swap(a, i, i/2);
        i = i/2;
    }
}

static void fixDown(ItemPQ a[], int i, int N){

    while (2*i <= N) {
    
        //Use int as it stores the floor of a double value
        int j = 2*i;       
        
        //Find the smaller of the two children   
        if (j < N && larger(a[j], a[j+1]) == 1) j++;
        
        //If the parent is smaller than the children then priority is restored
        if (larger(a[i], a[j]) == 0 && a[i].value != a[j].value) break;
        
        //Else the parent and smallest child swaps
        swap(a, i, j);
        i = j;
    }
}

static void swap(ItemPQ a[], int i, int j){

    ItemPQ tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

static int larger(ItemPQ a, ItemPQ b){

    if (a.value > b.value){
        return 1;
    } else {
        return 0;
    }
}

static void arrayCopy(ItemPQ *array1, ItemPQ *array2, int size){

    int i = 1;
    
    //Copy values in array1 into array2 one at a time
    while (i <= size){
        array2[i] = array1[i];
        i++;
    }
}

