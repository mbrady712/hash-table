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

    cout << "TESTING PART 1: CALLING GETCOUNT() AND PRINTtABLE() ON EMPTY TABLE" << endl;

    cout << "Result of getCount(): " << table.getCount() << endl;

    cout << "Result of printTable(): " << endl;

    table.printTable();

    cout << endl;

    // try and put ALL the test data into the table and show what happens

    cout << "TESTING PART 2: PUTTING ALL TEST DATA INTO THE TABLE" << endl;

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

    cout << "TESTING PART 3: RETRIEVING TEST DATA FROM THE TABLE" << endl;

    //Retrieving all test data

    cout << "Getting all test data from table (" << testdatasize << " entries)..."<< endl;
    for (int i = 0; i < testdatasize; i++) {
        string temp = table.getData(ids[i]);
        if(temp == ""){
            cout << "Failed: data with id of " << ids[i] << " is not in the table." << endl;
        }else{
            cout << "Success: data with id of " << ids[i] << " found and has string " << temp << endl;
        }
    }
    cout << endl;

    //Attempt to retrieve non-existent ID

    cout << "Attempting to retrieve a non-existent test data with id of " << MAXID + 1 << " from the table..." << endl;
    if (table.getData(MAXID + 1) == "") {
        cout << "Failed: data with id of " << MAXID + 1 << " is not in the table." << endl;
    }else{
        cout << "Success: data with id of " << MAXID + 1 << " found and has string " << table.getData(MAXID + 1) << endl;
    }
    cout << endl;

    //Remove the first, middle, and last three of the test data ids and one non-existent id

    cout << "TESTING PART 4: THOROUGHLY TESTING REMOVEENTRY()" << endl;

    //First

    cout << "Deleting first test data, which has id of " << ids[0] << endl;
    if (table.removeEntry(ids[0])) {
        cout << "Success: " << ids[0] << " removed" << endl;
    } else {
        cout << "Failed: " << ids[0] << " was not removed" << endl;
    }

    //Middle

    cout << "Deleting middle test data, which has id of " << ids[(int) (testdatasize - 1) / 2] << endl;
    if (table.removeEntry(ids[(int) (testdatasize - 1) / 2])) {
        cout << "Success: " << ids[(int) (testdatasize - 1) / 2] << " removed" << endl;
    } else {
        cout << "Failed: " << ids[(int) (testdatasize - 1) / 2] << " was not removed" << endl;
    }

    //Last three

    cout << "Deleting third-to-last test data, which has id of " << ids[testdatasize - 3] << endl;
    if (table.removeEntry(ids[testdatasize - 3])) {
        cout << "Success: " << ids[testdatasize - 3] << " removed" << endl;
    } else {
        cout << "Failed: " << ids[testdatasize - 3] << " was not removed" << endl;
    }

    cout << "Deleting second-to-last test data (known duplicate), which has id of " << ids[testdatasize - 2] << endl;
    if (table.removeEntry(ids[testdatasize - 2])) {
        cout << "Success: " << ids[testdatasize - 2] << " removed" << endl;
    } else {
        cout << "Failed: " << ids[testdatasize - 2] << " was not removed" << endl;
    }

    cout << "Deleting last test data (known bad), which has id of " << ids[testdatasize - 1] << endl;
    if (table.removeEntry(ids[testdatasize - 1])) {
        cout << "Success: " << ids[testdatasize - 1] << " removed" << endl;
    } else {
        cout << "Failed: " << ids[testdatasize - 1] << " was not removed" << endl;
    }

    //Non-existent test data

    cout << "Deleting non-existent test data, which has id of " << MAXID + 1 << endl;
    if (table.removeEntry(MAXID + 1)) {
        cout << "Success: " << MAXID + 1 << " removed" << endl;
    } else {
        cout << "Failed: " << MAXID + 1 << " was not removed" << endl;
    }

    cout << endl;

    cout << "Result of printTable() after deletions: " << endl;

    table.printTable();

    cout << endl;

    //Test removeEntry() on empty table

    //Empty the table

    cout << "Emptying table..." << endl;

    for (int i = 0; i < testdatasize; i++) {
        table.removeEntry(ids[i]);
    }

    cout << "Printing table to demonstrate that it is empty: " << endl;

    table.printTable();

    cout << endl;

    cout << "Attempting to remove each test data on empty table: " << endl;

    for (int i = 0; i < testdatasize; i++) {
        if (table.removeEntry(ids[i])) {
            cout << "Success: " << ids[i] << " removed" << endl;
        }else{
            cout << "Failed: " << ids[i] << " was not removed" << endl;
        }
    }

    cout << endl;

    /*
    The Following code tests random operations. insertEntry() and removeEntry() are called twice as often as getCount() and getData() 
    because they change the contents of the table and should be tested more rigorously.
    */

    cout << "TESTING PART 5: RANDOM OPERATIONS" << endl;

    int randIndex = 0;
    cout << "Filling table with random selections from test data..." << endl;
    for(int i = 0; i < testdatasize; i++){
        //Create a random index number to select a random test data
        randIndex = rand() % (testdatasize - 1);
        table.insertEntry(ids[randIndex], &strs[randIndex]);
    }

    cout << "Result of printTable() with table randomly filled: " << endl;
    table.printTable();
    cout << endl;
    
    int choice = rand() % CHOICES + 1;
    for (int i = 0; i < RANDOM_RUNS; i++) {
        randIndex = rand() % (testdatasize - 1);
        switch (choice) {
            case 1:
            case 2:
                //insertEntry()
                cout << "Random Operation " << i + 1 << ":" << endl;
                cout << "Result of insertEntry() attempting to insert test data with id of " << ids[randIndex] << ":" << endl;
                if (table.insertEntry(ids[randIndex], &strs[randIndex])) {
                    cout << "Success: " << ids[randIndex] << "entered into table" << endl;
                } else {
                    cout << "Failed: " << ids[randIndex] << " not entered" << endl;
                }
                cout << "Observe the change with result of printTable(): " << endl;
                table.printTable();
                break;
            case 3:
            case 4:
                //removeEntry()
                cout << "Random Operation " << i + 1 << ":" << endl;
                cout << "Result of removeEntry() attempting to remove test data with id of " << ids[randIndex] << ":" << endl;
                if (table.removeEntry(ids[randIndex])) {
                    cout << "Success: " << ids[randIndex] << " removed" << endl;
                }else{
                    cout << "Failed: " << ids[randIndex] << " was not removed" << endl;
                }
                cout << "Observe the change with result of printTable(): " << endl;
                table.printTable();
                break;
            case 5:
                //getData()
                cout << "Random Operation " << i + 1 << ":" << endl;
                cout << "Result of getData() attempting to retrieve test data with id of " << ids[randIndex] << ":" << endl;
                if(table.getData(ids[randIndex]) == ""){
                    cout << "Failed: data with id of " << ids[randIndex] << " is not in the table." << endl;
                }else{
                    cout << "Success: data with id of " << ids[randIndex] << " found and has string " << table.getData(ids[randIndex]) << endl;
                }
                break;
            case 6:
                //getCount()
                cout << "Random Operation " << i + 1 << ":" << endl;
                cout << "Result of getCount(): " << table.getCount() << endl;
                break;
        }
        cout << endl;
        choice = rand() % CHOICES + 1;
    }
    cout << "Testing complete." << endl;
    return 0;
}
