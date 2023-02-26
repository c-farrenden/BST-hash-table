// HTable.h
/*******************************/
// Name: Connor Farrenden
// Course: SENG1120 - Assignment 3
// Student Number: c3374676
// Description: This is the header file for the HTable class

// Include contents of BTNode.h
#include "BTNode.h"

// Define table size (size of array)
#define TABLE_SIZE 5000

// Macroguards
#ifndef HTABLE_H
#define HTABLE_H

// Template
template <typename T>
class HTable 
{
    // Members that can be accessed outside class
    public:
        // Constructor
        // Precondition: None
        // Postcondition: Constructs and initialises hash table and its private members
        HTable();

        // Destructor
        // Precondition: None
        // Postcondition: Destructs hash table by deleting and setting to null, removing memory from the heap when deleted
        ~HTable();

        // Main functions
        // Precondition: Table/array to add to
        // Postcondition: Adds
        void add(const T& value);

        // Precondition: None
        // Postcondition: Maps key to values
        int hashfun(const T& value);

        // Precondition: None
        // Postcondition: Returns length of hash table
        int length() const;

        // Precondition: None
        // Postcondition: Returns the size of array
        int tableSize() const;

        // Precondition: None
        // Postcondition: Prints hash table
        std::ostream& printTable(std::ostream& out);

        // Precondition: None
        // Postcondition: Removes passed in T data from hash table
        void remove(const T& data);

        // Precondition: None
        // Postcondition: Calculates and returns the amount of parts
        int calculateParts();

        // Precondition: None
        // Postcondition: Calculates and returns the amount of parts in inventory
        int calculateInventory();

        // Precondition: None
        // Postcondition: Calculates and returns the amount of parts less than specified in inventory
        int calculateLessThan(int part);
    
    // Members that cannot be accessed outside class
    private:
        T* data[TABLE_SIZE];
        int size;
};

// Non-member output operator
// Precondition: hash table to print
// Postcondition: Allows printing of hash tables
template <typename T>
std::ostream& operator << (std::ostream& out, HTable<T>& table);

#include "HTable.hpp"

#endif