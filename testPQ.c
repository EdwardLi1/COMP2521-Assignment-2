#include "PQ.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    PQ new = newPQ();
    ItemPQ one;
    one.key = 0;
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
    ItemPQ five;
    five.key = 10;
    five.value = 7;
    ItemPQ six;
    six.key = 11;
    six.value = 0;
    ItemPQ seven;
    seven.key = 12;
    seven.value = 1;
    ItemPQ eight;
    eight.key = 20;
    eight.value = 0;
    addPQ(new, one);
    addPQ(new, two);
    addPQ(new, three);
    addPQ(new, four);
    addPQ(new, five);
    addPQ(new, six);
    addPQ(new, seven);
    addPQ(new, eight);
    showPQ(new);

    printf("===========================================================\n");

    ItemPQ tmp;
    tmp.key = 10;
    tmp.value = 5;

    updatePQ(new, tmp);

    printf("\n");

    showPQ(new);

    printf("===========================================================\n");

    dequeuePQ(new);
    showPQ(new);

    printf("===========================================================\n");

    dequeuePQ(new);
    showPQ(new);

    printf("===========================================================\n");

    dequeuePQ(new);
    showPQ(new);

    printf("===========================================================\n");

    printf("\n");
    return EXIT_SUCCESS;
}
