#include <iostream>
#include "linkedList.h"


LinkedList* createList() {
    LinkedList *newList = new LinkedList();
    newList->head = NULL;

    return newList;
};

Node* getHead(LinkedList* lista) {
    return lista->head;
};

Node* createNode(void *value) {
    Node *tempNode = new Node();

    tempNode->valuePointer = value;
    tempNode->nextNode = NULL;

    return tempNode;
};

void pushNode(LinkedList* lista, void *value) {
    Node* newNode = createNode(value);

    if(lista->head == NULL) {
        lista->head = newNode;
    } else {
        Node* node = lista->head;

        while(node != NULL) {
            if(node->nextNode == NULL) {
                node->nextNode = newNode;
                node = NULL;
            } else {
                node = node->nextNode;
            }

        }
    }
};

void iterateList(LinkedList* lista, void callback(Node* node)) {
    Node* node = getHead(lista);

    if(node == NULL) {
        std::cout << "Lista vacia" << std::endl;
    } else {
        while (node != NULL) {
            callback(node);
            node = node->nextNode;
        }

        if(node == NULL) {
            std::cout<<"end" << std::endl;
        }
    }
}
