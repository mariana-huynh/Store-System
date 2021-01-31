//---------------------------------------------------------------------------
// Customer.h
// Header file for Customer class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Customer Class: child class of Action. Has pure virtual method. Prints out
//                 all transactions of the customer.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#ifndef Customer_h
#define Customer_h

#include "Transaction.h" 

//#include "Action.h"  
//#include "Store.h"

//#include "HashTable.h"  

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Customer : public Action
{
public:

	class HashTable;    // new

	// Constructor:		default constructor for Customer
	// Preconditions:	none
	// Postconditions:	Customer object is created with name =  noName and customerID = -1
	Customer();

	// Constructor:		constructs Customer from stream
	// Preconditions:	data is formatted according to specifications
	// Postconditions:	Customer object is created from istream
	Customer(istream& stream);

	// Destructor:		virtual to deallocate memory allocated in children
	// Preconditions:	destructor is virtual in children
	// Postconditions:	deallocates customerID, firstName, lastName, and history 
	virtual ~Customer();

	// getCustomerID:	gets the unique ID of the customer 
	// Preconditions:	customerID is a valid int
	// Postconditions:	customerID is returned
	const int getCustomerID() const;

	// setCustomerID:	sets customerID to iD
	// Preconditions:	iD is a valid int 
	// Postconditions:	customerID = iD
	void setCustomerID(int iD);

	// getFirstName:	gets name of customer
	// Preconditions:	name is a valid string
	// Postconditions:	returns name
	const string& getName() const;

	// setFirstName:	sets the name of the customer to n
	// Preconditions:	n is a valid string
	// Postconditions:	name = n
	void setName(const string& n);

	// getHistory:		gets the history of the customer
	// Preconditions:	history is a valid, not empty vector
	// Postconditions:	returns customer's transaction history in vector form
	const vector<Transaction*> getHistory() const;

	// perform:			performs some action (action different depending on child)
	// Preconditions:	children classes implement this pure virtual method
	// Postconditions:	prints out all transactions for a given customer
	virtual void perform(Store* store);

	// addToHistory:	adds a transaction to the customer history
	// Preconditions:	transaction is a valid transaction
	// Postconditions:	adds transaction to history vector 
	void addToHistory(Transaction* transaction);

	// operator<:			overloaded less than operator , compares Customers by name 
	// Preconditions:	a and b point to valid Customers
	// Postconditions:	returns true if a->getName() is a string less than b->getName() and false if vise verse
	bool operator<(const Customer& right) const;

private:
	int customerID;
	string name;
	vector<Transaction*> history;
};
#endif