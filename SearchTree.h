//---------------------------------------------------------------------------
// SearchTree.h
// Simple SearchTree Class 
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// SearchTree Class: simple binary search tree class storing Items.
// 
// Assumptions: 
//      - Pointer to data may cause memory leaks
//      - Invariant of binary search tree is not broken 
//---------------------------------------------------------------------------

#pragma once
#include "Item.h"   // Need for using Item in parameters 
#include <algorithm>   // for using max() 
#include <iostream>
using namespace std;

class SearchTree
{
    // operator <<:    overloaded insertion operator 
    // Preconditions:  tree != nullptr
    // Postconditions: ouputs the frequency table for the tree in sorted order (for chars: ACSII sorted order)
    friend ostream& operator<<(ostream& output, const SearchTree& tree);

public:
    // Default constructor:	creates an empty SearchTree
    // Preconditions:		none
    // Postconditions:		sets root = nullptr
    SearchTree();

    // Copy constructor: creates a SearchTree from a deep copy of toCopy 
    // Preconditions:    toCopy is a valid tree
    // Postconditions:   a copy of toCopy is constructed
    SearchTree(const SearchTree& other);

    // Destructor:	   deallocates memory associated with calling SearchTree
    // Preconditions:  none
    // Postconditions: calls makeEmpty()
    ~SearchTree();

    // operator =:	   overloaded assignment operator
    // Preconditions:  this->root and right.root are not equal to nullptr
    // Postconditions: this is deallocated and right is copied over to this
    const SearchTree& operator=(const SearchTree& right);

    // operator ==:    overloaded operator==
    // Preconditions:  this->root and right.root are not equal to nullptr
    // Postconditions: returns true if both trees have the same data, count for each key, and structure. returns true if 
    //                 both trees are empty.
    bool operator==(const SearchTree& right) const;

    // operator !=:    overloaded operator != 
    // Preconditions:  this->root and right.root are not equal to nullptr
    // Postconditions: returns the opposite of operator==
    bool operator!=(const SearchTree& right) const;

    // insert:         inserts Item c into the tree if not found and increments count for the key if found in tree
    // Preconditions:  *c is not nullptr
    // Postconditions: returns true if c is not in the tree and false for when c is in (instead increments count for that key)
    bool insert(Item* c);

    // remove:          removes one occurrence of c from the tree. If there is only one occurrence of c in the tree, the key 
    //                  is removed from the tree.
    // Preconditions:   none
    // Postconditions:  count of node containing c is decremented, or if count is == 1, key c is removed from the tree.
    bool remove(Item* c);

    // makeEmpty:	   deletes all nodes from the tree and deallocates the memory associated with them
    // Preconditions:  none
    // Postconditions: all nodes in the tree are removed and deallocated through preorder traversal and root = nullptr
    void makeEmpty();

    // retrieve:	   finds the Item in the SearchTree using key
    // Preconditions:  treeNode != nullptr
    // Postconditions: pointer to data associated with key is returned if found in the tree and nullptr returned if key not found 
    Item* retrieve(const Item& key) const;
   
    // height:
    // Preconditions:  key is a valid Item 
    // Postconditions: maximum depth (height) at key node is returned, returns -1 if tree is empty or key not found in the 
    //                 tree, returns 0 for a leaf node
    int height(const Item& key) const;

private:
    struct Node 
    {   
        Item* item;  // pointer to data can cause memory leaks 
        Node* leftChild;
        Node* rightChild;
        int count = 0;   // counts the number of occurances for a given key
    };

    Node* root;

    // copyTree:	   private recursive helper method for copy constructor
    // Preconditions:  copy constructor passes in toCopy.root into copyTree
    // Postconditions: each node of toCopy is copied (data and count) into new SearchTree instance
    Node* copyTree(const Node* nodePtr);

    // makeEmptyHelper: private recursive helper method for makeEmpty()
    // Preconditions:   makeEmpty() passes in root of tree to be deleted to makeEmptyHelper()
    // Postconditions:  preorder traversal of tree to delete all nodes and sets root to nullptr
    void makeEmptyHelper(Node*& treeNode);

    // heightHelper:   private recursive method for height() 
    // Preconditions:  findNode returned node with key 
    // Postconditions: returns the maximum depth (height) for treeNode (returns the left subtree maximum depth if left 
    //                 subtree is deeper than right subtree (and vise verse if right subtree is deeper), returns -1 if key
    //                 not found and for empty trees, returns 0 for leaf nodes
    int heightHelper(Node* treeNode) const;

    // findNode:       private recursive helper method for heightHelper() which helps height()
    // Preconditions:  root of tree to find node in is passed in as treeNode, treeNode != nullptr
    // Postconditions: the Node of key is returned if found in the tree and nullptr is returned if key is not found 
    Node* findNode(Node* treeNode, const Item& key) const;

    // retrieveHelper: private recurive helper method for retrieve()
    // Preconditions:  treeNode != nullptr
    // Postconditions: pointer to data associated with key is returned if found in the tree and nullptr returned if key not found 
    Item* retrieveHelper(const Node* treeNode, const Item& key) const;

    // insertHelper:   private recursive helper method for insert()
    // Preconditions:  *c is not nullptr
    // Postconditions: returns true if c is not in the tree and false for when c is in (instead increments count for that key)
    bool insertHelper(Node*& treeNode, Item* c);

    // printInOrder:   private recursive helper method for operator<<()
    // Preconditions:  treeNode != nullptr
    // Postconditions: traverses tree in order and prints out data of each node (Item and count)
    void printInOrder(Node* treeNode) const;

    // isEqualHelper:  private recursive helper method for isEqual()
    // Preconditions:  treeNode1 and treeNode2 are not equal to nullptr
    // Postconditions: returns true if both trees have the same data, count for each key, and structure. returns true if 
    //                 both trees are empty. 
    bool isEqualHelper(Node* treeNode1, Node* treeNode2) const;

    // removeHelper:    private helper method to remove. Deletes one occurrence of c from the tree.
    // Preconditions:   c must be a valid Item (in this case a char)
    // Postconditions:  removes one occurrence of c from the tree if c is in the tree (returns false if not in tree. 
    //                  Or if the last occurrence, removes the key from the tree.
    bool removeHelper(Node*& treeNode, Item* c);

    // deleteNode:      private helper method for removeHelper. Deletes the node specified in the parameter from the tree.
    // Preconditions:   treeNode is not equal to nullptr
    // Postconditions:  leaf = deleted, one child = deleted and parent points to treeNode's child, two children = treeNode->item
    //                  is now equal to value of most left
    //                  child of right branch (and then this node is deleted).
    void deleteNode(Node*& treeNode);

    // findAndDeleteMostLeft: private helper method for deleteNode. Finds the replacement node's data for the node
    //                       (with two children) to be deleted.
    // Preconditions:         treeNode is not nullptr
    // Postconditions:        the value of the replacement node is found and returned as a Item object type
    Item* findAndDeleteMostLeft(Node*& treeNode, int& tempCount);

};

