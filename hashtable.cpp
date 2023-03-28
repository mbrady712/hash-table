/* 
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a hash table that implements separate chaining.
 */

#include "hashtable.h"

//Public methods

bool HashTable::insertEntry(int id, string* Data){
    return true;
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