//---------------------------------------------------------------------------
// History.cpp
// Implementation file for History class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// History Class: child class of Action. Has pure virtual method. Prints out
//                the history for every customer.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#include "History.h"

// Destructor:		virtual to deallocate memory allocated in children
// Preconditions:	destructor is virtual in children
// Postconditions:	deallocates new memory allocated by child 
History::~History()
{

}

// perform:			performs some action (action different depending on child)
// Preconditions:	children classes implement this pure virtual method
// Postconditions:	history of every customer is printed (sell, buy)
void History::perform(Store* store)
{
	cout << endl << "History: " << endl;
	store->getCustomers().printCustomersHistory(store);
}

// getCustomerID:	gets the unique ID of the customer 
// Preconditions:	customerID is a valid int
// Postconditions:	customerID is returned
int History::getCustomerID() const
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
void History::setCustomerID(int iD)
{
	if (iD >= 0)
	{
		customerID = iD;
	}
}

