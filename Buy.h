//---------------------------------------------------------------------------
// Buy.cpp
// Header file for Buy class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Buy Class: child class of Transaction. Has pure virtual method. 
//            Performs buy: adds an item to the store inventory that customer
//            sold to store.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#ifndef Buy_h
#define Buy_h

#include "Customer.h"
#include "Store.h"

#include "Transaction.h" // here

class Buy : public Transaction
{
public:
	// Destructor:		virtual to deallocate memory allocated in children
	// Preconditions:	destructor is virtual in children
	// Postconditions:	deallocates any new memory allocated by children 
	virtual ~Buy();

	// perform:			performs some action (action different depending on child)
	// Preconditions:	children classes implement this pure virtual method
	// Postconditions:	adds an item to the store inventory and adds transaction to customer history
	virtual void perform(Store* store);

	// printTransaction:	pure virtual method for printing in children class
	// Preconditions:		children classes implement this method
	// Postconditions:		prints out character 'B', customerID, and item with spaces inbetween each
	virtual void printTransaction() const;

};
#endif

