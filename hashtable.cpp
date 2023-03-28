/* 
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a hash table that implements separate chaining.
 */

#include "hashtable.h"

//Public methods

HashTable::HashTable(){
    count = 0;
    for (int i = 0; i < HASHTABLESIZE; i++) {
        hashtable[i] = 0;
    }
}

HashTable::~HashTable(){

}

bool HashTable::insertEntry(int id, string* Data){
    bool inserted = false;


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

}

//Private methods

int HashTable::hash(int id){
    return id % HASHTABLESIZE;
}