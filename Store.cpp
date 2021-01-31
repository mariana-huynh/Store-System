//---------------------------------------------------------------------------
// Store.h
// Implementation file for Store class.
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

#include "Store.h"
#include "HashTable.h"
#include "ActionFactory.h"
#include "Customer.h"
#include "Action.h"

// new
#include "Transaction.h"

// Default Constructor:	creates a new store
// Preconditions:		constuctors for all member variables are written (for their classes)
// Postconditions:		member pointer variables point to new objects of their type
Store::Store()
{
	coinTree = new SearchTree();
	comicTree = new SearchTree();
	sportsCardTree = new SearchTree();
	customers = new HashTable();
}

// readInventoryList:	reads in inventory file (.txt file) and inserts items into SearchTrees 
// Preconditions:		file is in same directory as code, has the correct name, and is formatted according to specifications 
// Postconditions:		adds items to appropriate SearchTrees (e.g., coinTree for Coin)
void Store::readInventoryList()
{ 
	string inventoryFile = "hw4inventory.txt";
	fstream infile(inventoryFile);

	if (infile.fail())
	{
		cerr << "Cannot find inventory file: " << inventoryFile << endl;
		return;
	}

	while (!infile.eof()) 
	{
		Item* item = ItemFactory::create(infile);     

		if (item != nullptr)
		{
			if (item->getItemType() == ItemType::CoinType)
			{
				coinTree->insert(item); 
			}
			else if (item->getItemType() == ItemType::ComicType)
			{
				comicTree->insert(item);
			}
			else if (item->getItemType() == ItemType::SportsCardType)
			{
				sportsCardTree->insert(item);
			}
			else
			{
				cerr << "Unexpected Type: " << item->getItemType() << endl;
				continue;
			}
		}
	}
}

// readCommandList:	reads in customer file (.txt file) and creates actions
// Preconditions:	file is in same directory as code, has the correct name, and is formatted according to specifications
// Postconditions:	actions are created from read in file
void Store::readCommandList()
{
	string commandFile = "hw4commands.txt";
	fstream infile(commandFile);

	if (infile.fail())
	{
		cerr << "Cannot find commands file: " << commandFile << endl;
		return;
	}

	while (!infile.eof())
	{
		Action* action = ActionFactory::create(infile, this);      

		if (action != nullptr)
		{
			action->perform(this);
		}
	}
}

// readCustomerList: reads in customer file (.txt file) and creates customer instances
// Preconditions:	 file is in same directory as code, has the correct name, and is formatted according to specifications
// Postconditions:	 customers are created from read in file
void Store::readCustomerList()
{
	string customerFile = "hw4customers.txt";
	fstream infile(customerFile);

	if (infile.fail())
	{
		cerr << "Cannot find customers file: " << customerFile << endl;
		return;
	}

	while (!infile.eof())
	{
		Customer* customer = new Customer(infile);   

		if (customer != nullptr)
		{
			customers->addItem(customer->getCustomerID(), customer);
		}
	}
}


// getCoinTree:		gets the coin tree
// Preconditions:	coinTree exists and is a valid SearchTree
// Postconditions:	returns tree that holds coin items
const SearchTree& Store::getCoinTree() const 
{
	return *coinTree;
}

// getComicTree:	gets the comic tree
// Preconditions:	comicTree exists and is a valid SearchTree
// Postconditions:	returns tree that holds comic items
const SearchTree& Store::getComicTree() const
{
	return *comicTree;
}

// getSportsCardTree:	gets the sports card tree
// Preconditions:		sportsCardTree exists and is a valid SearchTree
// Postconditions:		returns tree that holds sports card items
const SearchTree& Store::getSportsCardTree() const
{
	return *sportsCardTree;
}

// getCustomers:	gets the customers hashtable 
// Preconditions:	customers exists and is a valid HashTable
// Postconditions:	returns HashTable that holds customer information 
const HashTable& Store::getCustomers() const
{
	return *customers;
}
