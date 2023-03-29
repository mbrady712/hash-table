/* 
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a hash table that implements separate chaining.
 */

#include "hashtable.h"

//Public methods

HashTable::HashTable(){
    count = 0;
}

bool HashTable::insertEntry(int id, string* data){
    bool inserted = false;
    //Check if id is positive int greater than 0 and that string is not empty
    if(id > 0 && *data != ""){
        inserted = hashtable[hash(id)].addNode(id, data);
        if(inserted){
            count++;
        }
    }
    return inserted;
}

string HashTable::getData(int id){
    Data data;
    data.data = "";
    if(id > 0){
        hashtable[hash(id)].getNode(id, &data);
    }
    return data.data;
}

bool HashTable::removeEntry(int id){
    bool removed = false;
    removed = hashtable[hash(id)].deleteNode(id);
    if(removed){
        count--;
    }
    return removed;
}

int HashTable::getCount(){
    return count;
}

void HashTable::printTable(){
    for(int i = 0; i < HASHTABLESIZE; i++){
        std::cout << "Entry " << i + 1 << ": "; 
        hashtable[i].printList();
    }
}

//Private methods

int HashTable::hash(int id){
    return id % HASHTABLESIZE;
}