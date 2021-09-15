#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#ifndef NULL
#define NULL      0
#endif

struct Node {
    void *valuePointer;
    Node *nextNode;
};


struct LinkedList {
    Node *head;
};

struct Direccion {
        std::string calle;
        int altura;
    };

LinkedList * createList();

Node* getHead(LinkedList* lista);

Node* createNode(void *value);

void pushNode(LinkedList* lista, void* value);

void iterateList(LinkedList* lista, void callback(Node* node));




#endif // LINKEDLIST_H_INCLUDED
