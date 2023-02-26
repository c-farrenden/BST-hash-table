// BSTree.hpp
/*******************************/
// Name: Connor Farrenden
// Course: SENG1120 - Assignment 3
// Student Number: c3374676
// Description: This is the hpp file for the BSTree class

// Include contents of BSTree.h
#include "BSTree.h"

// Constructor - initialises private member variables
template <typename T>
BSTree<T>::BSTree()
{
	root = NULL;
	size = 0;
}

// Destructor - calls removeNodes() function for deleting all nodes in BSTree
template <typename T>
BSTree<T>::~BSTree()
{
	removeAll(root);
}

// Recursive function for removing all nodes from BSTree that will be called from destructor
template <typename T>
void BSTree<T>::removeAll(BTNode<T>* root) 
{
    // Check if tree is empty
    if(root != NULL)
    {
        // Recursive calls for deletion of left and right children/subtrees
        removeAll(root->getLeft());
        removeAll(root->getRight());
	    // Delete root, set to NULL and decrement size
	    delete root;
        root = NULL;
	    size--;
    }
    // If tree is empty, return
    else
    {
        return;
    }
}

// Returns the size of the BSTree - isnt actually used/required
template <typename T>
int BSTree<T>::length() const
{
	return size;
}

// Add function - insert into tree
template <typename T>
void BSTree<T>::add(const T& data)
{
    // If root is empty, create a new node storing data, increment size
    if(root == NULL)
    {
        root = new BTNode<T>(data);
        size++;
    }
    // If not null, call insert() function to insert data
    else
    {
        insert(root, data);
    }
}

// Helper function for adding data to tree 
template <typename T>
BTNode<T>* BSTree<T>::insert(BTNode<T>* root, const T& data)
{
    // If data is at the root (equal), then replace data
    if(data == root->getData())
    {
        root->getData() = data;
    }
    // If data is greater than right subtree
    else if(data > root->getData())
    {
        // If no data in right subtree, set new data, increment size
        if(root->getRight() == NULL)
        {
            root->setRight(new BTNode<T>(data));
            size++;
        }
        // Recursive call if already contains data
        else
        {
            insert(root->getRight(), data);
        }
    }
    // If data is less than left subtree (do the same as right subtree)
    else
    {
        // If no data in left subtree, set new data, increment size
        if(root->getLeft() == NULL)
        {
            root->setLeft(new BTNode<T>(data));
            size++;
        }
        // Recursive call if already contains data
        else
        {
            insert(root->getLeft(), data);
        }
    }

    return root;
}

// This function allows printInOrder to be called (returned) and used in << operator to print tree contents
template <typename T>
std::ostream& BSTree<T>::printTree(std::ostream& out)
{
    return printInOrder(out, root);
}

// Function for performing inorder traversal through tree - will be called for later use
template <typename T>
std::ostream& BSTree<T>::printInOrder(std::ostream& out, BTNode<T>* root)
{
    // Check whether tree is empty, if not, then perform inorder traversal - left, root then right
    if(root != NULL)
    {
        // Check if left child is empty
        if(root->getLeft() != NULL)
        {
            // Recurse left child
            printInOrder(out, root->getLeft());
        }
        // Print data of root
        cout << root->getData() << " ";
        // Check if right child is empty
        if(root->getRight() != NULL)
        {
            // Recurse right child
            printInOrder(out, root->getRight());
        }
    }
   
    return out;
}

// Will print the contents of the tree by calling the PrintTree() function
template <typename T>
std::ostream& operator << (std::ostream& out, BSTree<T>& tree)
{
    return tree.printTree(out);
}

// Remove function - will call removeNodes() function and remove part specified in argument
template <typename T>
void BSTree<T>::remove(const T& data) 
{
	BTNode<T>* root = this->root;
	root = removeNodes(root, data);
}

// Remove function will remove from the tree based cases
template <typename T>
BTNode<T>* BSTree<T>::removeNodes(BTNode<T>* root, const T& data) 
{
    // If nothing to remove, return null root
    if(root == NULL)
    {
        return root;
    }
    // If data being deleted is less than root data, then its in the left sbutree
    else if(data < root->getData())
    {
        // Recursive call to remove the data in left subtree
        root->setLeft(removeNodes(root->getLeft(), data));
    }
    // If data being deleted is greater than root data, then its in the right sbutree
    else if(data > root->getData())
    {
        // Recursive call to remove the data in right subtree
        root->setRight(removeNodes(root->getRight(), data));
    }
    // Case 1: No children - if left and right is null, delete root and set to null, decrement size
    else if(root->getLeft() == NULL && root->getRight() == NULL)
    {
        delete root;
        root = NULL;
        size--;
    }
    // Case 2: 1 child - if right child is null
    else if(root->getRight() == NULL)
    {
        // Store root in a temporary node, set to left child and delete, decrement size
        BTNode<T>* tempNode = root;
        root = root->getLeft();
        delete tempNode;
        size--;
    }
    // If left child is null
    else if(root->getLeft() == NULL)
    {
        // Store root in a temporary node, set to right child and delete, decrement size
        BTNode<T>* tempNode = root;
        root = root->getRight();
        delete tempNode;
        size--;
    }
    // Case 3: 2 children - if left and right subtrees are not null (will essentially shuffle/replace nodes in tree)
    else if(root->getLeft() != NULL && root->getRight() != NULL)
    {
        // Store the minimum value of right child in temporary node
        BTNode<T>* tempNode = findMin(root->getRight());
        // Store the data in root for deletion
        root->setData(tempNode->getData());
        // Recursive call for setting and removing from right
        root->setRight(removeNodes(root->getRight(), tempNode->getData()));
        // Decrement size
        size--;
    }

    return root;
}

// Function that finds the minimum node - will need to be called in removeNodes() function
template <typename T>
BTNode<T>* BSTree<T>::findMin(BTNode<T>* const root)
{
    // If empty, return null root
	if (root == NULL) 
	{
		return root;
	}
	// If left subtree is empty, return root
	else if (root->getLeft() == NULL) 
    {
		return root;
	}
	// Return recursive for grabbing lowest
	return findMin(root->getLeft());
}

// Calculates the parts within tree
template <typename T>
int BSTree<T>::partsCalculation(BTNode<T>* tempNode) 
{
    // Initialise counter for counting parts
    int parts = 0;
    // If not empty, add each part for every node
    if(tempNode != NULL)
    {
        parts += partsCalculation(tempNode->getLeft());
        parts += partsCalculation(tempNode->getRight());
        parts++;
    }
    // Return the number of parts found
    return parts;
}

// Calls partsCalculation() and returns amount
template <typename T>
int BSTree<T>::calculateParts()
{
    return partsCalculation(root);
}

// Calculates the total parts in inventory within tree
template <typename T>
int BSTree<T>::inventoryCalculation(BTNode<T>* tempNode) 
{
    // Initialise counter for counting inventory parts
    int inventory = 0;
    // If not empty, go through tree and add the quantity of parts to counter
    if(tempNode != NULL)
    {
        inventory += inventoryCalculation(tempNode->getLeft());
        inventory += inventoryCalculation(tempNode->getRight());
        inventory += tempNode->getData().get_quantity();
    }
    // Return the number of parts in inventory
    return inventory;
}

// Calls inventoryCalculation() and returns amount
template <typename T>
int BSTree<T>::calculateInventory()
{
    return inventoryCalculation(root);
}

// Calculates the amount of parts that are less than specified in quantity
template <typename T>
int BSTree<T>::lessThanCalculation(BTNode<T>* tempNode)
{
    // Initialise counter
    int parts = 0;
    // Check if empty, go through tree
    if(tempNode != NULL)
    {  
        parts += lessThanCalculation(tempNode->getLeft());
        parts += lessThanCalculation(tempNode->getRight());
        // Check if part type is less than 10 in inventory, if so, increment parts counter
        if(tempNode->getData().get_quantity() < 10)
        {
            parts++;
        }
    }
    // Return the number of parts with less than specified (10) in inventory
    return parts;
}

// Calls lessThanCalculation() and returns amount
template <typename T>
int BSTree<T>::calculateLessThan(int part)
{
    return lessThanCalculation(root);
}