//---------------------------------------------------------------------------
// Customer.cpp
// Implementation file for Customer class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Customer Class: child class of Action. Has pure virtual method. Prints out
//                 all transactions of the customer.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#include "Customer.h"

#include "HashTable.h" // new


// Constructor:		default constructor for Customer
// Preconditions:	none
// Postconditions:	Customer object is created with name =  noName and customerID = -1
Customer::Customer()
{
	customerID = -1;
	name = "noName";
}

// Constructor:		constructs Customer from stream
// Preconditions:	data is formatted according to specifications
// Postconditions:	Customer object is created from istream
Customer::Customer(istream& stream)
{
	stream >> customerID;
	stream.ignore(2, '\n');
	getline(stream >> ws, name, '\n');
}

// Destructor:		virtual to deallocate memory allocated in children
// Preconditions:	destructor is virtual in children
// Postconditions:	deallocates customerID, firstName, lastName, and history 
Customer::~Customer()
{

}

// getCustomerID:	gets the unique ID of the customer 
// Preconditions:	customerID is a valid int
// Postconditions:	customerID is returned
const int Customer::getCustomerID() const
{
	if (this == nullptr)
	{
		cout << "Customer is nullptr." << endl;
		return -1;
	}
	else if (customerID >= 0 && customerID <= 999)
	{
		return customerID;
	}
	else
	{
		cout << "Customer ID is invalid." << endl;
		return -1;
	}
}

// setCustomerID:	sets customerID to iD
// Preconditions:	iD is a valid int 
// Postconditions:	customerID = iD
void Customer::setCustomerID(int iD)
{
	if (iD >= 0)
	{
		customerID = iD;
	}
}

// getFirstName:	gets name of customer
// Preconditions:	name is a valid string
// Postconditions:	returns name
const string& Customer::getName() const
{
	if (this == nullptr)
	{
		string* err = new string;
		*err = "error";
		cout << "Customer is nullptr." << endl;
		return *err;
	}
	else
	{
		return name;
	}
}

// setFirstName:	sets the name of the customer to n
// Preconditions:	name is a valid string
// Postconditions:	name = n
void Customer::setName(const string& n)
{
	name = n;    // assume formatted according to specifications
}

// getHistory:		gets the history of the customer
// Preconditions:	history is a valid, not empty vector
// Postconditions:	returns customer's transaction history in vector form
const vector<Transaction*> Customer::getHistory() const
{
	return history;
}

// perform:			performs some action (action different depending on child)
// Preconditions:	children classes implement this pure virtual method
// Postconditions:	prints out all transactions for a given customer
void Customer::perform(Store* store)
{
	int cID;
	cout << "Enter a customer ID to print the transaction history: ";
	cin >> cID;
	Customer* customer = store->getCustomers().getItem(cID);
	cout << "Customer transaction history for customer with ID " << cID << ":" << endl;

	if (customer == nullptr)
	{
		cerr << "Invalid customer ID: " << cID << endl;
		return;
	}

	const vector<Transaction*>& history = customer->getHistory();

	for (unsigned int i = 0; i < history.size(); i++)
	{
		history[i]->printTransaction();
	}
}

// addToHistory:	adds a transaction to the customer history
// Preconditions:	transaction is a valid transaction
// Postconditions:	adds transaction to history vector 
void Customer::addToHistory(Transaction* transaction)
{
	history.push_back(transaction);
}

// operator<:			overloaded less than operator , compares Customers by name 
// Preconditions:	a and b point to valid Customers
// Postconditions:	returns true if a->getName() is a string less than b->getName() and false if vise verse
bool Customer::operator<(const Customer& right) const
{
	return getName() < right.getName();
}