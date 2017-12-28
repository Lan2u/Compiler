// https://stackoverflow.com/questions/228684/how-to-declare-a-structure-in-a-header-that-is-to-be-used-by-multiple-files-in-c

#ifndef LinkedListString
#define LinkedListString

struct Node;
struct StringLinkedList;

struct Node{
    struct Node* next;
    char element;
};

typedef struct StringLinkedList{
    struct Node* head;
    struct Node* tail;
    long size;
};

struct Node* createNextNode(struct Node* node, char element);

int add(struct StringLinkedList* list, char element);

#endif