/* 
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a hash table that implements separate chaining.
 */

#ifndef HASH_TABLE
#define HASH_TABLE

#include "data.h"
#include "linkedlist.h"
#include <iostream>

class HashTable {

public:
    bool insertEntry(int, string*);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();

private:
    int hash(int);
    
};

#endif //HASH_TABLE