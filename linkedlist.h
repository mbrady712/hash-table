/*********************
Name: Michael Brady
Programming Fundamentals III
Purpose: This program contians a doubly Linked List ADT.
**********************/
#ifndef LINKED_LIST
#define LINKED_LIST

#include "data.h"
#include <iostream>

class LinkedList {

public:
    LinkedList();
    bool addNode(int, string*); 
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false); 
    int getCount();
    bool clearList();
    bool exists(int);
    ~LinkedList();

private:
    Node *head; 
    bool addFirst(int, string*, bool);
    bool addHead(int, string*, bool);
    bool addMiddle(int, string*, Node*, bool);
    bool addTail(int, string*, Node*, bool);
    Node* createNode(int, string*);
    bool deleteHead(int, Node*, bool);
    bool deleteMiddle(int, Node*, bool);
    bool deleteTail(int, Node*, bool);
    Node* getTail(Node*);
};

#endif //LINKED_LIST
