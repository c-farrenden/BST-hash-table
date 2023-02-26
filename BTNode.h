// BTNode.h
/*******************************/
// Name: Connor Farrenden
// Course: SENG1120 - Assignment 3
// Student Number: c3374676
// Description: This is the header file for the BTNode class

// Include contents of MechPart.h
#include "MechPart.h"

// Macroguards
#ifndef BTNODE_H
#define BTNODE_H

// Template
template <typename T>
class BTNode 
{   
    // Members that can be accessed outside class
    public:
        // Constructor
        // Precondition: None
        // Postcondition: Node is created and passed data of T
        BTNode(const T& data);

        // Destructor
        // Precondition: None
        // Postcondition: Removes all nodes from heap
        ~BTNode(); 
        
        // Setters
        // Precondition: None
        // Postcondition: Set the data in node
        void setData(const T& data);

        // Precondition: None
        // Postcondition: Sets the parent pointer
        void setParent(BTNode<T>* parent);

        // Precondition: None
        // Postcondition: Sets the left pointer
        void setLeft(BTNode<T>* left);

        // Precondition: None
        // Postcondition: Sets the right pointer
        void setRight(BTNode<T>* right);

        // Getters
        // Precondition: Requires type data
        // Postcondition: Returns data from pointer/node
        T getData() const;

        // Precondition: Requires parent pointer
        // Postcondition: Gets parent pointer and returns value
        BTNode<T>* getParent() const;

        // Precondition: Requires right pointer
        // Postcondition: Gets right pointer and returns value
        BTNode<T>* getRight() const;

        // Precondition: Requires left pointer
        // Postcondition: Gets left pointer and returns value
        BTNode<T>* getLeft() const;

    // Members that cannot be accessed outside BTNode class - includes underlying data of type T and parent, left and right BTNodes
    private:
        T data;
        BTNode<T>* parent;
        BTNode<T>* left;
        BTNode<T>* right;
};

#include "BTNode.hpp"

#endif