//---------------------------------------------------------------------------
// Transaction.h
// Header file for Transaction class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Transaction Class: child class of Action. Parent class to Sell and Buy.
//                    Has pure virtual method. 
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#ifndef Transaction_h
#define Transaction_h

#include "Action.h"
#include "Item.h"
#include "Store.h" 

#include "HashTable.h"    // new

class Transaction : public Action
{
public:
	// Destructor:		virtual to deallocate memory allocated in children
	// Preconditions:	destructor is virtual in children
	// Postconditions:	deallocates customerID 
	virtual ~Transaction();

	// printTransaction:	pure virtual method for printing in children class
	// Preconditions:		children classes implement this method
	// Postconditions:		prints something (depends on child class)
	virtual void printTransaction() const = 0;

	// getCustomerID:	gets the unique ID of the customer 
	// Preconditions:	customerID is a valid int
	// Postconditions:	customerID is returned
	int getCustomerID() const;

	// setCustomerID:	sets customerID to iD
	// Preconditions:	iD is a valid int 
	// Postconditions:	customerID = iD
	void setCustomerID(int iD);

	// getItem():		gets the item type
	// Preconditions:	item is a valid item with a valid item type (from enum ItemType)
	// Postconditions:	item is returned 
	Item* getItem() const;

	// setItem():		sets the item type
	// Preconditions:	i is a valid item with a valid ItemType
	// Postconditions:	item = i:
	void setItem(Item* i);

	// perform:			performs some action (action different depending on child)
	// Preconditions:	children classes implement this pure virtual method
	// Postconditions:	does nothing, children do something
	virtual void perform(Store* store);

private:
	int customerID;
	Item* item;

};
#endif

