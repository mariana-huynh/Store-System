//---------------------------------------------------------------------------
// Buy.cpp
// Implementation file for Buy class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Buy Class: child class of Transaction. Has pure virtual method. 
//            Performs buy: adds an item to the store inventory that customer
//            sold to store.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#include "Buy.h"

// Destructor:		virtual to deallocate memory allocated in children
// Preconditions:	destructor is virtual in children
// Postconditions:	deallocates any new memory allocated by children 
Buy::~Buy()
{

}

// perform:			performs some action (action different depending on child)
// Preconditions:	children classes implement this pure virtual method
// Postconditions:	adds an item to the store inventory and adds transaction to customer history
void Buy::perform(Store* store)
{
	Customer* customer = store->getCustomers().getItem(getCustomerID());

	if (customer == nullptr)
	{
		cerr << "Invalid customer ID: " << getCustomerID() << endl;
		return;
	}

	if (getItem()->getItemType() == ItemType::CoinType)
	{
		// store->getCoinTree().insert(getItem());
		static_cast<SearchTree>(store->getCoinTree()).insert(getItem());
		getItem()->increaseStock(1);
		customer->addToHistory(this);   
	}
	else if (getItem()->getItemType() == ItemType::ComicType)
	{
		static_cast<SearchTree>(store->getComicTree()).insert(getItem());
		getItem()->increaseStock(1);
		customer->addToHistory(this);   
	}
	else if (getItem()->getItemType() == ItemType::SportsCardType)
	{
		static_cast<SearchTree>(store->getSportsCardTree()).insert(getItem());
		getItem()->increaseStock(1);
		customer->addToHistory(this);  
	}
	else
	{
		cerr << "Invalid item type: " << getItem() << endl;
		return;
	}
}

// printTransaction:	pure virtual method for printing in children class
// Preconditions:		children classes implement this method
// Postconditions:		prints out character 'B', customerID, and item with spaces inbetween each
void Buy::printTransaction() const
{
	cout << "B " << getCustomerID() << " " << *getItem() << endl;
}
