/*********************
Name: Michael Brady
Programming Fundamentals III
Purpose: This program contians a doubly Linked List ADT.
**********************/

#include "linkedlist.h"

//Public methods

LinkedList::LinkedList(){
    head = NULL;
}

bool LinkedList::addNode(int id, string* data){
    bool success = false;

    //Check if id is positive int greater than 0 and that string is not empty
    if(id > 0 && *data != ""){
        if(head == NULL){//If list is empty
            success = addFirst(id, data, success);
        }else{
            Node *current = head; 
            while(current && success == false && id != current->data.id){
                if(id < head->data.id){//add new head case
                    success = addHead(id, data, success);
                }else if(id < current->data.id){//general case
                    success = addMiddle(id, data, current, success);
                }else if(current->next == NULL){//add new tail case
                    success = addTail(id, data, current, success);
                }
                current = current->next;
            }
        }
    }
    return success;
}

bool LinkedList::deleteNode(int id){
    bool success = false;
    Node *current = head; 
    if(id > 0){
        while(current && success == false){
            if(id == head->data.id){//delete head case
                success = deleteHead(id, current, success);
            }else if(id == current->data.id && current->next != NULL){//general case
                success = deleteMiddle(id, current, success);
            }else if(id == current->data.id && current->next == NULL){//delete tail case
                success = deleteTail(id, current, success);
            }
            current = current->next;
        }
    }
    return success;
}

bool LinkedList::getNode(int id, Data* data){
    bool success = false;
    Node *current = head; 
    while(current){
        if (id == current->data.id){
            data->id = current->data.id;
            data->data = current->data.data;
            success = true; 
        }
        current = current->next;
    }
    return success;
}

void LinkedList::printList(bool backward){
    int count = 1;
    Node *current = head; 
    if(head == NULL){//If list is empty
        std::cout << "\tList is empty" << std::endl;
    }else if(!backward){
        while(current){
            std::cout << "\t" << count << ": " << current->data.id << " : " << current->data.data << std::endl;
            current = current->next;
            count++;
        }
        std::cout << std::endl;
    }else{
        current = getTail(current);
        while(current){
            std::cout << "\t" << count << ": " << current->data.id << " : " << current->data.data << std::endl;
            current = current->prev;
            count++;
        }
        std::cout << std::endl;
    }
}

int LinkedList::getCount(){
    int count = 0;
    Node *current = head; 
    while(current){
        current = current->next;
        count++;
    }
    return count;
}

bool LinkedList::clearList(){
    bool success = false;
    Node *current = head;
    while(current){
        delete head;
        current = current->next;
        head = current;
    }
    if(!current){
        success = true;
    }
    head = NULL;
    return success;
}

bool LinkedList::exists(int id){
    bool success = false;
    Node *current = head; 
    while(current){
        if (id == current->data.id){
            success = true;
        }
        current = current->next;
    }
    return success;
}

LinkedList::~LinkedList(){
    clearList();
}

//Private methods

//Methods used by addNode()

bool LinkedList::addFirst(int id, string* data, bool success){
    //Create node dynamically
    Node *newNode = createNode(id, data);

    //Add it to the list
    head = newNode;
    newNode->next = NULL;
    newNode->prev = NULL;
    success = true;
    return success;
}

bool LinkedList::addHead(int id, string* data, bool success){
    Node *newNode = createNode(id, data);
    head->prev = newNode;
    newNode->next = head;
    newNode->prev = NULL;
    head = newNode;
    success = true;
    return success;
}

bool LinkedList::addMiddle(int id, string* data, Node* current, bool success){
    Node *newNode = createNode(id, data);
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
    success = true;
    return success;
}

bool LinkedList::addTail(int id, string* data, Node* current, bool success){
    Node *newNode = createNode(id, data);
    newNode->next = NULL;  
    newNode->prev = current;
    current->next = newNode;
    success = true;
    return success;
}

Node* LinkedList::createNode(int id, string* data){
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;
    return newNode;
}

//Methods used by deleteNode()

bool LinkedList::deleteHead(int id, Node* current, bool success){
    if(current->next == NULL){//If only one item in list
        head = NULL;
    }else{
        current->next->prev = NULL;
        head = current->next;
    }
    delete current;
    success = true;
    return success;
}

bool LinkedList::deleteMiddle(int id, Node* current, bool success){
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    success = true;
    return success;
}

bool LinkedList::deleteTail(int id, Node* current, bool success){
    current->prev->next = NULL;
    delete current;
    success = true;
    return success;
}

//Methods used by printList()

Node* LinkedList::getTail(Node* current){
    bool tail = false;
    while(current && !tail){
        if (current->next){
            current = current->next;
        } else {
            tail = true;
        }
    }
    return current;
}
