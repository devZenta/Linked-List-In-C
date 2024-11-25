//
// Created by zenta on 22/11/2024.
//

#include "List.h"
#include <stdlib.h>

int ListLength(struct List *list) {
    int length = 0;
    struct ListElement* temp = list->firstElement;
    while (temp != NULL) {
        length++;
        temp = temp->nextElement;
    }
    return length;
}

int ListGet(struct List *list, int index) {
    struct ListElement* temp = list->firstElement;
    for (int i = 0; i < index; i++) {
        temp = temp->nextElement;
    }
    return temp->value;
}

void ListAdd(struct List *list, int value) {
    struct ListElement* newElement = malloc (sizeof(struct ListElement));
    newElement->value = value;
    newElement->nextElement = NULL;
    if (list->firstElement == NULL) {
        list->firstElement = newElement;
        return;
    }
    struct ListElement* temp = list->firstElement;
    while (temp->nextElement != NULL) {
        temp = temp->nextElement;
    }
    temp->nextElement = newElement;
}


bool ListRemove(struct List *list, int index) {
    struct ListElement* temp = list->firstElement;
    struct ListElement* prev = NULL;
    int i = 0;
    while (temp != NULL) {
        if (i == index) {
            if (prev == NULL) {
                list->firstElement = temp->nextElement;
            } else {
                prev->nextElement = temp->nextElement;
            }
            free(temp);
            return true;
        }
        i++;
        prev = temp;
        temp = temp->nextElement;
    }
    return false;
}