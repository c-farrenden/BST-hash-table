// BTNode.hpp
/*******************************/
// Name: Connor Farrenden
// Course: SENG1120 - Assignment 3
// Student Number: c3374676
// Description: This is the hpp file for the BTNode class

// Include contents of BTNode.h
#include "BTNode.h"

// Constructor - initialises private members
template <typename T>
BTNode<T>::BTNode(const T& data)
{
    this->data = data;
	parent = NULL;
	left = NULL;
	right = NULL;
}

// Destructor - set pointers to null
template <typename T>
BTNode<T>::~BTNode()
{
	parent = NULL;
	left = NULL;
	right = NULL;
}

// Set the data in the node
template <typename T>
void BTNode<T>::setData(const T& data)
{
	this->data = data;
}

// Set parent node
template <typename T>
void BTNode<T>::setParent(BTNode<T>* parent)
{
	this->parent = parent;
}

// Set left node
template <typename T>
void BTNode<T>::setLeft(BTNode<T>* left)
{
	this->left = left;
}

// Set right node
template <typename T>
void BTNode<T>::setRight(BTNode<T>* right)
{
	this->right = right;
}

// Get data stored in node
template <typename T>
T BTNode<T>::getData() const
{
	return data;
}

// Get parent node
template <typename T>
BTNode<T>* BTNode<T>::getParent() const
{
	return parent;
}

// Get right node
template <typename T>
BTNode<T>* BTNode<T>::getRight() const
{
	return right;
}

// Get left node
template <typename T>
BTNode<T>* BTNode<T>::getLeft() const
{
	return left;
}