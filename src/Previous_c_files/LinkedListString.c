#include <stdio.h>
#include <string.h>
#include "LinkedListString.h"

// Add the given element to the next node after this node and then return the next node.
struct Node* createNextNode(struct Node* node, char element){
    struct Node newNode;
    newNode.element = element;
    node->next = &newNode;
    return &newNode;
}

// Add the given element char to the given list and return the new size.
int add(struct StringLinkedList* list, char element){
    if (list->head == NULL){
        struct Node newNode;
        newNode.element = element;
        list->head = &newNode;
        list->tail = list->head;
    }else{
        list->tail = createNextNode(list->tail, element);
    }
    list->size++;
    return list->size;
}