// BSTree.h
/*******************************/
// Name: Connor Farrenden
// Course: SENG1120 - Assignment 3
// Student Number: c3374676
// Description: This is the header file for the BSTree class

// Include contents of Node.h
#include "BTNode.h"

// Macroguards
#ifndef BSTREE_H
#define BSTREE_H

// Template
template <typename T>
class BSTree 
{
    // Members that can be accessed outside class
    public:
        // Precondition: None
        // Postcondition: Constructs BSTree with T data
        BSTree();

        // Precondition: None
        // Postcondition: Destructs tree by deleting all nodes (root)
        ~BSTree();

        // Precondition: None
        // Postcondition: Adds data to tree by calling insert()
        void add(const T& data);

        // Precondition: None
        // Postcondition: Removes all nodes from tree
        void removeAll(BTNode<T>* root);

        // Precondition: None
        // Postcondition: Returns length of tree
        int length() const;

        // Precondition: None
        // Postcondition: Removes passed in data from tree by calling removeNodes()
        void remove(const T& data);

        // Precondition: None
        // Postcondition: Prints the tree in order by calling printInOrder()
        std::ostream& printTree(std::ostream& out);
        
        // Precondition: None
        // Postcondition: Finds the lowest node in subtree
        BTNode<T>* findMin(BTNode<T>* const root);

        // Precondition: None
        // Postcondition: Calculates and returns the amount of parts by calling partsCalculation()
        int calculateParts();

        // Precondition: None
        // Postcondition: Calculates and returns the amount of parts in inventory by calling inventoryCalculation()
        int calculateInventory();

        // Precondition: None
        // Postcondition: Calculates and returns the amount of parts less than specified in inventory by calling lessThanCalculation()
        int calculateLessThan(int part);

    // Members that cannot be accessed outside class - includes helper functions
    private:
        BTNode<T>* root;
        int size;

        // Precondition: None
        // Postcondition: Adds data to tree
        BTNode<T>* insert(BTNode<T>* root, const T& data);

        // Precondition: None
        // Postcondition: Removes passed in data from tree
        BTNode<T>* removeNodes(BTNode<T>* root, const T& data);

        // Precondition: None
        // Postcondition: Prints the tree in order
        std::ostream& printInOrder(std::ostream& out, BTNode<T>* root);

        // Precondition: None
        // Postcondition: Calculates and returns the amount of parts
        int partsCalculation(BTNode<T>* tempNode); 

        // Precondition: None
        // Postcondition: Calculates and returns the amount of parts in inventory
        int inventoryCalculation(BTNode<T>* tempNode); 

        // Precondition: None
        // Postcondition: Calculates and returns the amount of parts less than specified in inventory
        int lessThanCalculation(BTNode<T>* tempNode);
};

// Non-member output operator
// Precondition: Tree to print
// Postcondition: Allows printing of trees by calling printTree()
template <typename T>
std::ostream& operator << (std::ostream& out, BSTree<T>& tree);

#include "BSTree.hpp"

#endif