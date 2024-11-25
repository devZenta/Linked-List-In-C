//
// Created by zenta on 22/11/2024.
//

#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

struct ListElement {
    int value;
    struct ListElement *nextElement;
};

struct List {
    struct ListElement *firstElement;
};

int ListLength(struct List *list);
int ListGet(struct List *list, int index);
void ListAdd(struct List *list, int value);
bool ListRemove(struct List *list, int index);

#endif //LIST_H
