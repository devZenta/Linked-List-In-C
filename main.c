#include <stdio.h>
#include "List.h"

int main(void) {
    printf("Linked List :\n");
    printf("\n");

    struct List list = {NULL};

    int nbElement = 0;
    printf("How many elements do you want to add to the list ?\n");
    scanf("%d", &nbElement);

    for (int i = 0; i < nbElement; i++) {
        int value = 0;
        printf("Enter the value of the element %d\n", i);
        scanf("%d", &value);
        ListAdd(&list, value);
    }

    printf("\n");
    printf("List length: %d\n", ListLength(&list));

    printf("\n");

    for (int i = 0; i < ListLength(&list); i++) {
        printf("Value at index %d: %d\n", i, ListGet(&list, i));
    }

    printf("\n");

    int removeInput = 0;
    printf("Do you want to remove an element at the list ?\n");
    printf("0: No | 1: Yes\n");
    scanf("%d", &removeInput);
    if (removeInput == 1) {
        int index = 0;
        printf("Enter the index of the element you want to remove\n");
        scanf("%d", &index);
        if (ListRemove(&list, index)) {
            printf("Value at index %d removed\n", index);
        } else {
            printf("Value at index %d not removed\n", index);
        }
    }

    printf("\n");
    printf("List length: %d\n", ListLength(&list));

    for (int i = 0; i < ListLength(&list); i++) {
        printf("Value at index %d: %d\n", i, ListGet(&list, i));
    }

    return 0;
}