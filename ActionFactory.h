//---------------------------------------------------------------------------
// ActionFactory.h
// Header file for ActionFactory class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// ActionFactory Class: reads data from the .txt file and creates Actions.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#ifndef ActionFactory_h
#define ActionFactory_h

#include "Action.h"
#include "Display.h"
#include "History.h"
#include "Sell.h"
#include "Item.h"
#include "Buy.h"
#include "Customer.h"
#include "Coin.h"
#include "Comic.h"
#include "SportsCard.h"
#include <iostream>
#include "Store.h"

using namespace std;

class ActionFactory
{
public:
	// create:			reads from file and creates actions
	// Preconditions:	file is formatted according to specifications
	// Postconditions:	actions are created from read in file
	static Action* create(istream& stream, Store* store);

private:
	// createDisplay:	creates Display (which prints out the inventory)
	// Preconditions:	file is formatted according to specifications
	// Postconditions:	returns newly constructed Display
	static Display* createDisplay(istream& stream, Store* store);

	// createHistory:	creates a history for a customer
	// Preconditions:	file is formatted according to specifications
	// Postconditions:	new History is constructed 
	static History* createHistory(istream& stream, Store* store);

	// createSell:		creates Sell transaction
	// Preconditions:	file is formatted according to specifications
	// Postconditions:	creates Sell transaction for customer with read in customer ID
	static Sell* createSell(istream& stream, Store* store);

	// createBuy:		creates Buy transaction
	// Preconditions:	file is formatted according to specifications
	// Postconditions:	creates Buy transaction for customer with read in customer ID
	static Buy* createBuy(istream& stream, Store* store);

	// createCustomer:	creates Customer
	// Preconditions:	file is formatted according to specifications
	// Postconditions:	creates Customer with read in customer ID
	static Customer* createCustomer(istream& stream, Store* store);

	// findItem:		finds an Item according to read in file
	// Preconditions:	file is formatted according to specifications
	// Postconditions:	finds an Item of type specified by char in read in file
	static Item* findItem(istream& stream, Store* store);

	// findCoin:		finds item of type Coin
	// Preconditions:	file is formatted according to specifications
	// Postconditions:	returns the Coin if exists in coinTree
	static Coin* findCoin(istream& stream, Store* store);

	// findComic:		finds item of type Comic
	// Preconditions:	file is formatted according to specifications
	// Postconditions:	returns the Comic if exists in comicTree
	static Comic* findComic(istream& stream, Store* store);

	// findSportsCard:	finds item of type SportsCard
	// Preconditions:	file is formatted according to specifications
	// Postconditions:	returns the SportsCard if exists in sportsCardTree
	static SportsCard* findSportsCard(istream& stream, Store* store);

};
#endif

