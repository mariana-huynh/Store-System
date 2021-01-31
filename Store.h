//---------------------------------------------------------------------------
// Store.h
// Header file for Store class.
// Author: Mariana Huynh 
//---------------------------------------------------------------------------
// Store Class: reads in inventory, customer, and command text files. Stores
//              item data into three SearchTrees (one for coins, one for 
//              comics, and one for sports cards). Customers stored inside a
//              hashtable.
//
// Assumptions: all text files are named accordingly and exist in the same 
//              directory as the code and is formatted as described in the
//              specifications (may have errors). 
//---------------------------------------------------------------------------

#ifndef Store_h
#define Store_h

#include <iostream>
#include <fstream>
#include "ItemFactory.h"
#include "Item.h"
#include "SearchTree.h"

using namespace std;

// forward declarations
class HashTable;
class ActionFactory;
class Customer;
class Action;

// new
class Transaction;

class Store
{
public:
	// Default Constructor:	creates a new store
	// Preconditions:		constuctors for all member variables are written (for their classes)
	// Postconditions:		member pointer variables point to new objects of their type
	Store();

	// readInventoryList:	reads in inventory file (.txt file) and inserts items into SearchTrees 
	// Preconditions:		file is in same directory as code, has the correct name, and is formatted according to specifications 
	// Postconditions:		adds items to appropriate SearchTrees (e.g., coinTree for Coin)
	void readInventoryList();

	// readCommandList:	reads in customer file (.txt file) and creates actions
	// Preconditions:	file is in same directory as code, has the correct name, and is formatted according to specifications
	// Postconditions:	actions are created from read in file
	void readCommandList();

	// readCustomerList: reads in customer file (.txt file) and creates customer instances
	// Preconditions:	 file is in same directory as code, has the correct name, and is formatted according to specifications
	// Postconditions:	 customers are created from read in file
	void readCustomerList();


	// getCoinTree:		gets the coin tree
	// Preconditions:	coinTree exists and is a valid SearchTree
	// Postconditions:	returns tree that holds coin items
	const SearchTree& getCoinTree() const;

	// getComicTree:	gets the comic tree
	// Preconditions:	comicTree exists and is a valid SearchTree
	// Postconditions:	returns tree that holds comic items
	const SearchTree& getComicTree() const;

	// getSportsCardTree:	gets the sports card tree
	// Preconditions:		sportsCardTree exists and is a valid SearchTree
	// Postconditions:		returns tree that holds sports card items
	const SearchTree& getSportsCardTree() const;

	// getCustomers:	gets the customers hashtable 
	// Preconditions:	customers exists and is a valid HashTable
	// Postconditions:	returns HashTable that holds customer information 
	const HashTable& getCustomers() const;
	

private:
	SearchTree* coinTree;
	SearchTree* comicTree;
	SearchTree* sportsCardTree;
	HashTable* customers;

};
#endif

