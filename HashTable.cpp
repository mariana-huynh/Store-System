//---------------------------------------------------------------------------
// HashTable.cpp
// Implementation file for HashTable class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// HashTable Class: holds Customers and customer data.
// 
// Assumptions: uses separate chaining. Pointer to data could cause 
//              memory leaks.
//---------------------------------------------------------------------------

#include "HashTable.h"

// Constructor:		creates an empty hashtable
// Preconditions:	none
// Postconditions:	empty hashtable with all elements in hashtable array set to null
HashTable::HashTable()
{
	buildTable();
}

// buildTable:		private helper method for constructor, creates an empty hashtable
// Preconditions:	none
// Postconditions:	empty hashtable with all elements in hashtable array set to null
void HashTable::buildTable()
{
	for (int i = 0; i < SIZE; i++)
	{
		table[i] = nullptr;   // table[i] = head of list
	}
}

// Destrcutor:		deletes all items from the hashtable
// Preconditions:	HashTable exists 
// Postconditions:	all items in hashtable are deleted and pointers are set to nullptr
HashTable::~HashTable()
{
	makeEmpty();
}

// makeEmpty:		private helper method for destructor, deletes all items from the hashtable
// Preconditions:	HashTable exists 
// Postconditions:	all items in hashtable are deleted and pointers are set to nullptr
void HashTable::makeEmpty()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (table[i] != nullptr)
		{
			ItemList* cur = table[i];

			while (cur != nullptr)
			{
				table[i] = table[i]->next;
				delete cur->data;
				delete cur;
				cur = nullptr;
				cur = table[i];
			}
		}
	}
}

// getItem:			returns item that has the k (in this case a Customer with some customer ID)
// Preconditions:	k is a valid int
// Postconditions:	returns item with k 
Customer* HashTable::getItem(int k) const
{
	if (k >= 0 && k <= 999)
	{
		int hashIndex = k % SIZE;   // SIZE = number of buckets

		if (table[hashIndex] == nullptr)
		{
			return nullptr;
		}
		else
		{
			ItemList* cur = table[hashIndex];

			while (cur != nullptr)
			{
				if (cur->key == k)
				{
					return cur->data;
				}

				cur = cur->next;
			}
		}

		return nullptr;
	}

	return nullptr;
}

// addItem:			add the item c into the hashtable, also checks for duplicate items
// Preconditions:	c points to a valid Customer and is not nullptr, k is a valid int
// Postconditions:	adds c into the hashtable with int k 
void HashTable::addItem(int k, Customer* c)
{
	if (k >= 0 && k <= 999)
	{
		int hashIndex = k % SIZE;

		ItemList* newItemList = new ItemList;
		newItemList->data = c;
		newItemList->key = k;
		newItemList->next = nullptr;

		if (table[hashIndex] == nullptr)
		{
			newItemList->next = table[hashIndex];
			table[hashIndex] = newItemList;       // insert at head
			return;
		}
		else       // for more than one ItemList node
		{
			ItemList* cur = table[hashIndex];

			while (cur->next != nullptr)   // changed from cur != nullptr
			{
				if (cur->key == k)
				{
					delete newItemList->data;
					delete newItemList;
					cout << "Cannot add same key." << endl;
					return;
				}

				cur = cur->next;
			}

			cur->next = newItemList;   // add c to the end of the linked list
		}
	}
}

// getSIZE:			returns the size of the hashtable array
// Preconditions:	none
// Postconditions:	returns static const int SIZE
const int HashTable::getSIZE()  const
{
	if (SIZE >= 0)
	{
		return SIZE;
	}
}

// printCustomerHistory:	prints out the history for every customer in the hashtable array 
//                          with customers listed in alphabetical order
// Preconditions:			ItemList::key and Customer::customerID are equal to each other, 
//                          store is pointing to a valid Store
// Postconditions:			all transactions for every customer in hashtable is printed out 
//                          in alphabetical order according to customer name
void HashTable::printCustomersHistory(Store* store) const
{
	vector<Customer> cust;

	for (int i = 0; i < SIZE; i++)
	{
		if (table[i] == nullptr)
		{
			continue;
		}

		ItemList* cur = table[i];    // points to head of list

		while (cur != nullptr)
		{
			cust.push_back(*cur->data);
			cur = cur->next;
		}
	}

	sort(cust.begin(), cust.end());            

	for (unsigned int i = 0; i < cust.size(); i++)
	{
		cout << cust[i].getCustomerID() << " " << cust[i].getName() << endl;
		Customer* customer = store->getCustomers().getItem(cust[i].getCustomerID());

		if (customer == nullptr)
		{
			cerr << "Invalid customer ID: " << cust[i].getCustomerID() << endl;
			return;
		}

		const vector<Transaction*>& history = customer->getHistory();

		for (unsigned int i = 0; i < history.size(); i++)
		{
			history[i]->printTransaction();
		}
	}
}

