//---------------------------------------------------------------------------
// Sell.cpp
// Implementation file for Sell class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Sell Class: child class of Transaction. Has pure virtual method. 
//             Performs sell: removes an item from the store inventory that 
//             customer bought from store.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#include "Sell.h"

// Destructor:		virtual to deallocate memory allocated in children
// Preconditions:	destructor is virtual in children
// Postconditions:	deallocates any new memory allocated by children 
Sell::~Sell()
{

}

// perform:			performs some action (action different depending on child)
// Preconditions:	children classes implement this pure virtual method
// Postconditions:	removes an item from the store inventory and adds transaction to customer
void Sell::perform(Store* store)
{
	Customer* customer = store->getCustomers().getItem(getCustomerID());

	if (customer == nullptr)
	{
		cerr << "Invalid customer ID: " << getCustomerID() << endl;
		return;
	}

	if (getItem()->getItemType() == ItemType::CoinType)
	{
		if (static_cast<SearchTree>(store->getCoinTree()).remove(getItem()) == false)
		{
			cout << "Item to sell not found: " << getItem() << endl;
			return;
		}

		static_cast<SearchTree>(store->getCoinTree()).remove(getItem());
		getItem()->decreaseStock();
		customer->addToHistory(this);
	}
	else if (getItem()->getItemType() == ItemType::ComicType)
	{
		if (static_cast<SearchTree>(store->getComicTree()).remove(getItem()) == false)
		{
			cout << "Item to sell not found: " << getItem() << endl;
			return;
		}

		static_cast<SearchTree>(store->getComicTree()).remove(getItem());
		getItem()->decreaseStock();
		customer->addToHistory(this);
	}
	else if (getItem()->getItemType() == ItemType::SportsCardType)
	{
		if (static_cast<SearchTree>(store->getSportsCardTree()).remove(getItem()) == false)
		{
			cout << "Item to sell not found: " << getItem() << endl;
			return;
		}

		static_cast<SearchTree>(store->getSportsCardTree()).remove(getItem());
		getItem()->decreaseStock();
		customer->addToHistory(this);
	}
	else
	{
		cerr << "Invalid item type: " << endl;
		return;
	}
}

// printTransaction:	pure virtual method for printing in children class
// Preconditions:		children classes implement this method
// Postconditions:		prints out character 'S ', customerID, and item with spaces inbetween each
void Sell::printTransaction() const
{
	cout << "S " << getCustomerID() << " " << *getItem() << endl;
}
