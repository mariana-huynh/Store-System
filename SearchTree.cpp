//---------------------------------------------------------------------------
// SearchTree.cpp
// Member function definitions for the SearchTree class
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// SearchTree Class: simple binary search tree class storing Items.
//                   Items in this case are chars, but SearchTree
//                   written generically
//
// Assumptions: 
//      - Pointer to data may cause memory leaks
//      - Invariant of binary search tree is not broken 
//---------------------------------------------------------------------------

#include "SearchTree.h"

// Default constructor:	creates an empty SearchTree
// Preconditions:		none
// Postconditions:		sets root = nullptr
SearchTree::SearchTree()
{
	this->root = nullptr;
}

// Copy constructor: creates a SearchTree from a deep copy of toCopy 
// Preconditions:    toCopy is a valid tree
// Postconditions:   a copy of toCopy is constructed
SearchTree::SearchTree(const SearchTree& toCopy)
{
	root = copyTree(toCopy.root);
}

// copyTree:	   private recursive helper method for copy constructor
// Preconditions:  copy constructor passes in toCopy.root into copyTree
// Postconditions: each node of toCopy is copied (data and count) into new SearchTree instance
SearchTree::Node* SearchTree::copyTree(const Node* toCopy)     
{
	Node* copyNode = nullptr;

	if (toCopy != nullptr)
	{
		// preorder traversal
		copyNode = new Node;
		copyNode->item = toCopy->item;
		copyNode->count = toCopy->count;
		copyNode->leftChild = copyTree(toCopy->leftChild);
		copyNode->rightChild = copyTree(toCopy->rightChild);
	}

	return copyNode;
}

// Destructor:	   deallocates memory associated with calling SearchTree
// Preconditions:  none
// Postconditions: calls makeEmpty()
SearchTree::~SearchTree()
{
	makeEmpty();
}

// makeEmpty:	   deletes all nodes from the tree and deallocates the memory associated with them
// Preconditions:  none
// Postconditions: all nodes in the tree are removed and deallocated through preorder traversal and root = nullptr
void SearchTree::makeEmpty()
{
	makeEmptyHelper(root);
}

// makeEmptyHelper: private recursive helper method for makeEmpty()
// Preconditions:   makeEmpty() passes in root of tree to be deleted to makeEmptyHelper()
// Postconditions:  preorder traversal of tree to delete all nodes and sets root to nullptr
void SearchTree::makeEmptyHelper(SearchTree::Node*& treeNode)
{
	if (treeNode != nullptr)
	{
		makeEmptyHelper(treeNode->leftChild);
		makeEmptyHelper(treeNode->rightChild);
		delete treeNode;
		treeNode = nullptr;  // if don't do this = dangling pointer 
	}
}

// operator =:	   overloaded assignment operator
// Preconditions:  this->root and right.root are not equal to nullptr
// Postconditions: this is deallocated and right is copied over to this
const SearchTree& SearchTree::operator=(const SearchTree& right)
{
	if (this != &right)
	{
		this->makeEmpty();
		this->root = copyTree(right.root);
	}

	return *this;
}

// operator ==:    overloaded operator==
// Preconditions:  this->root and right.root are not equal to nullptr
// Postconditions: returns true if both trees have the same data, count for each key, and structure. returns true if 
//                 both trees are empty.
bool SearchTree::operator==(const SearchTree& right) const
{
	return isEqualHelper(this->root, right.root);
}

// isEqualHelper:  private recursive helper method for isEqual()
// Preconditions:  treeNode1 and treeNode2 are not equal to nullptr
// Postconditions: returns true if both trees have the same data, count for each key, and structure. returns true if 
//                 both trees are empty. 
bool SearchTree::isEqualHelper(Node* treeNode1, Node* treeNode2) const      
{
	if (treeNode1 == nullptr && treeNode2 == nullptr)     // return true if both empty
	{
		return true;
	}
	else if ((treeNode1 == nullptr && treeNode2 != nullptr) || (treeNode1 != nullptr && treeNode2 == nullptr))
	{
		return false;
	}
	else if (*treeNode1->item == *treeNode2->item && treeNode1->count == treeNode2->count)   
	{
		// if both true then true 
		return isEqualHelper(treeNode1->leftChild, treeNode2->leftChild) && isEqualHelper(treeNode1->rightChild, treeNode2->rightChild);    
	}
	else
	{
		return false;
	}
}

// operator !=:    overloaded operator != 
// Preconditions:  this->root and right.root are not equal to nullptr
// Postconditions: returns the opposite of operator==
bool SearchTree::operator!=(const SearchTree& right) const
{
	return !(*this == right);
}

// insert:         inserts Item c into the tree if not found and increments count for the key if found in tree
// Preconditions:  *c is not nullptr
// Postconditions: returns true if c is not in the tree and false for when c is in (instead increments count for that key)
bool SearchTree::insert(Item* c)
{
	return insertHelper(root, c);
}

// insertHelper:   private recursive helper method for insert()
// Preconditions:  *c is not nullptr
// Postconditions: returns true if c is not in the tree and false for when c is in (instead increments count for that key)
bool SearchTree::insertHelper(Node*& treeNode, Item* c)
{
	if (c == nullptr)   // check if inserting nullptr
	{
		return false;
	}
	else if (treeNode == nullptr)
	{
		treeNode = new Node;
		treeNode->item = c;
		treeNode->leftChild = nullptr;      // always insert at a leaf
		treeNode->rightChild = nullptr;
		treeNode->count++;
		return true;
	}
	else if (*treeNode->item == *c)
	{
		treeNode->count++;   // already in tree, increment count
		return false;
	}
	else if (*treeNode->item > *c)
	{
		return insertHelper(treeNode->leftChild, c);
	}
	else
	{
		return insertHelper(treeNode->rightChild, c);
	}
}

// remove:          removes one occurrence of c from the tree. If there is only one occurrence of c in the tree, the key 
//                  is removed from the tree.
// Preconditions:   none
// Postconditions:  count of node containing c is decremented, or if count is == 1, key c is removed from the tree.
bool SearchTree::remove(Item* c)
{
	return removeHelper(root, c);
}

// removeHelper:    private helper method to remove. Deletes one occurrence of c from the tree.
// Preconditions:   c must be a valid Item (in this case a char)
// Postconditions:  removes one occurrence of c from the tree if c is in the tree (returns false if not in tree. 
//                  Or if the last occurrence, removes the key from the tree.
bool SearchTree::removeHelper(Node*& treeNode, Item* c)
{
	if (treeNode == nullptr)
	{
		return false;
	}
	else if (treeNode->item == c)           
	{
		if (treeNode->count == 1)   // only remove key if only one occurrence in tree
		{
			deleteNode(treeNode);
			return true;
		}

		treeNode->count--;
		return true;
	}
	else if (*treeNode->item > * c)
	{
		return removeHelper(treeNode->leftChild, c);
	}
	else
	{
		return removeHelper(treeNode->rightChild, c);
	}
}

// deleteNode:      private helper method for removeHelper. Deletes the node specified in the parameter from the tree.
// Preconditions:   treeNode is not equal to nullptr
// Postconditions:  leaf = deleted, one child = deleted and parent points to treeNode's child, two children = treeNode->item
//                  is now equal to value of most left
//                  child of right branch (and then this node is deleted).
void SearchTree::deleteNode(Node*& treeNode)
{
	if (treeNode->leftChild == nullptr && treeNode->rightChild == nullptr)      // no children
	{
		delete treeNode;
		treeNode = nullptr;
	}
	else if (treeNode->leftChild == nullptr || treeNode->rightChild == nullptr)     // one child
	{
		Node* temp = treeNode;
		treeNode = treeNode->leftChild == nullptr ? treeNode->rightChild : treeNode->leftChild;
		delete temp;
	}
	else     // two children
	{
		int tempCount = 0;
		// replace item with most left child of right branch
		treeNode->item = findAndDeleteMostLeft(treeNode->rightChild, tempCount);
		treeNode->count = tempCount;			// fix
	}
}

// findAndDeleteMostLeft: private helper method for deleteNode. Finds the replacement node's data for the node
//                       (with two children) to be deleted.
// Preconditions:         treeNode is not nullptr
// Postconditions:        the value of the replacement node is found and returned as a Item object type
Item* SearchTree::findAndDeleteMostLeft(Node*& treeNode, int& tempCount)
{
	if (treeNode->leftChild == nullptr)    // want to get leaf
	{
		Item* c = treeNode->item;
		Node* temp = treeNode;
		tempCount = temp->count;  
		treeNode = treeNode->rightChild;
		delete temp;
		return c;    
	}
	else
	{
		return findAndDeleteMostLeft(treeNode->leftChild, tempCount);
	}
}

// retrieve:	   finds the Item in the SearchTree using key
// Preconditions:  treeNode != nullptr
// Postconditions: pointer to data associated with key is returned if found in the tree and nullptr returned if key not found 
Item* SearchTree::retrieve(const Item& key) const
{
	Item* found = retrieveHelper(root, key);
	return found;
}

// retrieveHelper: private recurive helper method for retrieve()
// Preconditions:  treeNode != nullptr
// Postconditions: pointer to data associated with key is returned if found in the tree and nullptr returned if key not found 
Item* SearchTree::retrieveHelper(const Node* treeNode, const Item& key) const
{
	if (treeNode == nullptr)
	{
		return nullptr;   // key not found
	}
	else if (*treeNode->item == key)
	{
		return treeNode->item;   // key found
	}
	else if (*treeNode->item > key)
	{
		// search the left subtree
		return retrieveHelper(treeNode->leftChild, key);
	}
	else
	{
		// search the right subtree
		return retrieveHelper(treeNode->rightChild, key);
	}
}

// height:
// Preconditions:  key is a valid Item 
// Postconditions: maximum depth (height) at key node is returned, returns -1 if tree is empty or key not found in the 
//                 tree, returns 0 for a leaf node
int SearchTree::height(const Item& key) const
{
	Node* found = findNode(root, key);
	return heightHelper(found);
}

// heightHelper:   private recursive method for height() 
// Preconditions:  findNode returned node with key 
// Postconditions: returns the maximum depth (height) for treeNode (returns the left subtree maximum depth if left 
//                 subtree is deeper than right subtree (and vise verse if right subtree is deeper), returns -1 if key
//                 not found and for empty trees, returns 0 for leaf nodes
int SearchTree::heightHelper(Node* treeNode) const
{
	if (treeNode == nullptr)
	{
		return -1;
	}
	
	return 1 + max(heightHelper(treeNode->leftChild), heightHelper(treeNode->rightChild));
}

// findNode:       private recursive helper method for heightHelper() which helps height()
// Preconditions:  root of tree to find node in is passed in as treeNode, treeNode != nullptr
// Postconditions: the Node of key is returned if found in the tree and nullptr is returned if key is not found 
SearchTree::Node* SearchTree::findNode(Node* treeNode, const Item& key) const
{
	// traverse tree preorder
	// empty tree
	if (treeNode == nullptr)
	{
		return nullptr;
	}
	else if (*treeNode->item == key)
	{
		return treeNode;
	}
	else if (*treeNode->item > key)
	{
		return findNode(treeNode->leftChild, key);
	}
	else
	{
		return findNode(treeNode->rightChild, key);
	}
}

// operator <<:    overloaded insertion operator 
// Preconditions:  tree != nullptr
// Postconditions: ouputs the frequency table for the tree in sorted order (for chars: ACSII sorted order)
ostream& operator<<(ostream& output, const SearchTree& tree)
{
	tree.printInOrder(tree.root);
	return output;
}

// printInOrder:   private recursive helper method for operator<<()
// Preconditions:  treeNode != nullptr
// Postconditions: traverses tree in order and prints out data of each node (Item and count)
void SearchTree::printInOrder(Node* treeNode) const
{
	if (treeNode == nullptr)
	{
		return;
	}

	// left child
	printInOrder(treeNode->leftChild);

	// current
	//cout << *treeNode->item << " " << treeNode->count << endl;
	cout << *treeNode->item << endl;

	// right child
	printInOrder(treeNode->rightChild);
}