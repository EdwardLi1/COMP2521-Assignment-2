#include "PQ.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    PQ new = newPQ();
    ItemPQ one;
    one.key = 1;
    one.value = 2;
    ItemPQ two;
    two.key = 2;
    two.value = 3;
    ItemPQ three;
    three.key = 4;
    three.value = 2;
    ItemPQ four;
    four.key = 3;
    four.value = 1;
    addPQ(new, one);
    addPQ(new, two);
    addPQ(new, three);
    addPQ(new, four);
    showPQ(new);
    
  return EXIT_SUCCESS;
}
