//---------------------------------------------------------------------------
// Transaction.cpp
// Implementation file for Transaction class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Transaction Class: child class of Action. Parent class to Sell and Buy.
//                    Has pure virtual method. 
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#include "Transaction.h"

// Destructor:		virtual to deallocate memory allocated in children
// Preconditions:	destructor is virtual in children
// Postconditions:	deallocates customerID 
Transaction::~Transaction()
{

}

// getCustomerID:	gets the unique ID of the customer 
// Preconditions:	customerID is a valid int
// Postconditions:	customerID is returned
int Transaction::getCustomerID() const
{
	if (customerID >= 0)
	{
		return customerID;
	}
	else
	{
		return -1;
	}
}

// setCustomerID:	sets customerID to iD
// Preconditions:	iD is a valid int 
// Postconditions:	customerID = iD
void Transaction::setCustomerID(int iD)
{
	if (iD >= 0)
	{
		customerID = iD;
	}
}

// getItem():		gets the item type
// Preconditions:	item is a valid item with a valid item type (from enum ItemType)
// Postconditions:	item is returned 
Item* Transaction::getItem() const
{
	return item;
}

// setItem():		sets the item type
// Preconditions:	i is a valid item with a valid ItemType
// Postconditions:	item = i
void Transaction::setItem(Item* i)
{
	item = i;
}

// perform:			performs some action (action different depending on child)
// Preconditions:	children classes implement this pure virtual method
// Postconditions:	does nothing, children do something
void Transaction::perform(Store* store)
{

}
