//---------------------------------------------------------------------------
// History.h
// Header file for History class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// History Class: child class of Action. Has pure virtual method. Prints out
//                the history for every customer.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#ifndef History_h
#define History_h

#include "Store.h"
#include "Action.h"
#include "HashTable.h"

class History : public Action
{
public:
	// Destructor:		virtual to deallocate memory allocated in children
	// Preconditions:	destructor is virtual in children
	// Postconditions:	deallocates new memory allocated by child 
	virtual ~History();
	
	// perform:			performs some action (action different depending on child)
	// Preconditions:	children classes implement this pure virtual method
	// Postconditions:	history of every customer is printed (sell, buy)
	virtual void perform(Store* store);

	// getCustomerID:	gets the unique ID of the customer 
	// Preconditions:	customerID is a valid int
	// Postconditions:	customerID is returned
	int getCustomerID() const;

	// setCustomerID:	sets customerID to iD
	// Preconditions:	iD is a valid int 
	// Postconditions:	customerID = iD
	void setCustomerID(int iD);

private:
	int customerID;

};
#endif
