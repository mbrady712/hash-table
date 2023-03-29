/* 
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a hash table that implements separate chaining.
 */

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here

    HashTable table;
    
    // show it is empty by calling getCount and printTable

    cout << "Table starts empty." << endl;

    cout << "Result of getCount(): " << table.getCount() << endl;

    cout << "Result of printTable(): " << endl;

    table.printTable();

    cout << endl;

    // try and put ALL the test data into the table and show what happens

    cout << "Filling table with all of test data (" << testdatasize << " entries)..."<< endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << "Adding data: " << ids[i] << " : " << strs[i] << endl;
        table.insertEntry(ids[i], &strs[i]);
    }

    cout << endl;

    cout << "Result of getCount(): " << table.getCount() << endl;

    cout << "Result of printTable(): " << endl;

    table.printTable();

    cout << endl;

    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    //Test getData() on every element when table is full
    cout << "Getting test data from table (" << testdatasize << " entries)..."<< endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << "Data with id of " << ids[i] << " has string " << table.getData(ids[i]) << endl;
    }

    return 0;
}
