//---------------------------------------------------------------------------
// Sell.h
// Header file for Sell class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Sell Class: child class of Transaction. Has pure virtual method. 
//             Performs sell: removes an item from the store inventory that 
//             customer bought from store.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#ifndef Sell_h
#define Sell_h

#include "Customer.h"
#include "Store.h"

#include "Transaction.h" // here

class Sell : public Transaction
{
public:
	// Destructor:		virtual to deallocate memory allocated in children
	// Preconditions:	destructor is virtual in children
	// Postconditions:	deallocates any new memory allocated by children 
	virtual ~Sell();

	// perform:			performs some action (action different depending on child)
	// Preconditions:	children classes implement this pure virtual method
	// Postconditions:	removes an item from the store inventory and adds transaction to customer
	virtual void perform(Store* store);

	// printTransaction:	pure virtual method for printing in children class
	// Preconditions:		children classes implement this method
	// Postconditions:		prints out character 'S ', customerID, and item with spaces inbetween each
	virtual void printTransaction() const;

};
#endif
