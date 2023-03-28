/* 
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a hash table that implements separate chaining.
 */

#include "hashtable.h"

//Public methods

bool HashTable::insertEntry(int id, string* data){
    bool inserted = false;
    //Check if id is positive int greater than 0 and that string is not empty
    if(id > 0 && *data != ""){
        hashtable[hash(id)].addNode(id, data);
        inserted = true;
    }
    return inserted;
}

string HashTable::getData(int id){
    return "hello";
}

bool HashTable::removeEntry(int id){
    return true;
}

int HashTable::getCount(){
    return 1;
}

void HashTable::printTable(){
    for(int i = 0; i < HASHTABLESIZE; i++){
        std::cout << "Entry" << i + 1 << ": "; 
        hashtable[i].printList();
    }
}

//Private methods

int HashTable::hash(int id){
    return id % HASHTABLESIZE;
}