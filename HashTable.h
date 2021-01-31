//---------------------------------------------------------------------------
// HashTable.h
// Header file for HashTable class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// HashTable Class: holds Customers and customer data.
// 
// Assumptions: uses separate chaining. Pointer to data could cause 
//              memory leaks.
//---------------------------------------------------------------------------

#ifndef HashTable_h
#define HashTable_h

#include "Customer.h"
#include "Store.h"
#include <iostream>
#include <algorithm>   // for using std::sort
using namespace std;

class HashTable
{
public:
	// Constructor:		creates an empty hashtable
	// Preconditions:	none
	// Postconditions:	empty hashtable with all elements in hashtable array set to null
	HashTable();

	// Destrcutor:		deletes all items from the hashtable
	// Preconditions:	HashTable exists 
	// Postconditions:	all items in hashtable are deleted and pointers are set to nullptr
	~HashTable();

	// getItem:			returns item that has the k (in this case a Customer with some customer ID)
	// Preconditions:	k is a valid int
	// Postconditions:	returns item with k 
	Customer* getItem(int k) const;

	// addItem:			add the item c into the hashtable, also checks for duplicate items
	// Preconditions:	c points to a valid Customer and is not nullptr, k is a valid int
	// Postconditions:	adds c into the hashtable with int k 
	void addItem(int k, Customer* c);

	// getSIZE:			returns the size of the hashtable array
	// Preconditions:	none
	// Postconditions:	returns static const int SIZE
	const int getSIZE()  const;

	// printCustomerHistory:	prints out the history for every customer in the hashtable array 
	//                          with customers listed in alphabetical order
	// Preconditions:			ItemList::key and Customer::customerID are equal to each other, 
	//                          store is pointing to a valid Store
	// Postconditions:			all transactions for every customer in hashtable is printed out 
	//                          in alphabetical order according to customer name
	void printCustomersHistory(Store* store) const;

private:
	static const int SIZE = 50;   // hopefully big enough

	struct ItemList   // linked list node 
	{
		Customer* data;   // holds Customers 
		int key;          // customer ID
		ItemList* next;
	};

	ItemList* table[SIZE];    // hashtable array of linked lists 

	// makeEmpty:		private helper method for destructor, deletes all items from the hashtable
	// Preconditions:	HashTable exists 
	// Postconditions:	all items in hashtable are deleted and pointers are set to nullptr
	void makeEmpty();

	// buildTable:		private helper method for constructor, creates an empty hashtable
	// Preconditions:	none
	// Postconditions:	empty hashtable with all elements in hashtable array set to null
	void buildTable();

};
#endif
