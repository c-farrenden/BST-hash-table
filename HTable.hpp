// HTable.hpp
/*******************************/
// Name: Connor Farrenden
// Course: SENG1120 - Assignment 3
// Student Number: c3374676
// Description: This is the hpp file for the HTable class

// Includes contents of HTable.h
#include "HTable.h"

// Constructor - constructs array and sets to null
template <typename T>
HTable<T>::HTable()
{
    // Creates/loops through array and sets all hash data to null
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        data[i] = NULL;
    }
    // Set size to 0
    size = 0;
}

// Destructor - loops through array and deletes indexes
template <typename T>
HTable<T>::~HTable()
{
    // Loop through array and delete each index-value pair and set to null
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        delete data[i];
        data[i] = NULL;
    }
    size = 0;
}

// Return size of hash table (data)
template <typename T>
int HTable<T>::length() const
{
    return size;
}

// Return size of array
template <typename T>
int HTable<T>::tableSize() const
{
    return TABLE_SIZE;
}

// Hash function - maps keys to values
template <typename T>
int HTable<T>::hashfun(const T& value) 
{
    int position = 0;
    string temp = value.get_code();
    for (int i=0; i<(int)temp.length(); i++)
    {
        position += (i+1) * (i+1) * temp.at(i);
    }
    return position % TABLE_SIZE;
}

// Adds key-value pair to hash table
template <typename T>
void HTable<T>::add(const T& value)
{
    // Create location for storing value (hash)
    int hash = hashfun(value);
    // Check if empty, if so create a new T pointer of T value and store in position of hash, increment size
    if(data[hash] == NULL)
    {
        data[hash] = new T(value);
        size++;
    }
}

// Prints out the value of each index containing a value
template <typename T>
std::ostream& HTable<T>::printTable(std::ostream& out)
{
    // Loop through array
    for(int i = 0; i < tableSize(); i++)
    {
        // If index contains data, print out the value of the pointer (dereference)
        if(data[i] != NULL)
        {
            cout << *(data[i]) << " ";
        }
    }
    
    return out;
}

// Non-member output operator allows printing of hash tables by calling the printTable() function
template <typename T>
std::ostream& operator << (std::ostream& out, HTable<T>& table)
{
    return table.printTable(out);
}

// Remove function for removing data of type T
template <typename T>
void HTable<T>::remove(const T& value)
{
    // Create location for storing value (hash)
    int hash = hashfun(value);
    // If position of hash is not null, delete that data at that position and set to null, decrement size
    if(data[hash] != NULL)
    {
        delete data[hash];
        data[hash] = NULL;
        size--;
    }
}

// Will calculate the amount of parts found within the hash table
template <typename T>
int HTable<T>::calculateParts()
{
    // Initialise counter for counting parts
    int parts = 0;
    // Loop through array
    for(int i = 0; i < tableSize(); i++)
    {
        // If index contains data, increment the parts counter
        if(data[i] != NULL)
        {
            parts++;
        }
    }
    // Return the number of parts found
    return parts;
}

// Will calculate the total parts in inventory within the hash table
template <typename T>
int HTable<T>::calculateInventory()
{
    // Initialise counter for counting inventory parts
    int inventory = 0;
    // Loop through array
    for(int i = 0; i < tableSize(); i++)
    {
        // If index contains data, add the quantity of parts to inventory counter
        if(data[i] != NULL)
        {
            inventory += data[i]->get_quantity();
        }
    }
    // Return number of parts in inventory
    return inventory;
}

// Function that calculates parts that are less than number specified
template <typename T>
int HTable<T>::calculateLessThan(int part)
{
    // Initialise counter
    int parts = 0;
    // Loop through array
    for(int i = 0; i < tableSize(); i++)
    {
        // Check if hash index contains data
        if(data[i] != NULL)
        {
            // If the quantity of data is less than part (10), increment the counter
            if(data[i]->get_quantity() < part)
            {
                parts++;
            }
        }
    }
    // Return the number of parts with less than specified (10) in inventory
    return parts;
}