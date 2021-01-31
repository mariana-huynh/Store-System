//---------------------------------------------------------------------------
// ItemFactory.h
// Header file for ItemFactory class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// ItemFactory Class: reads data from the .txt file and creates Items.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#ifndef ItemFactory_h
#define ItemFactory_h

#include "Item.h"
#include "Coin.h"
#include "Comic.h"
#include "SportsCard.h"

#include <iostream>
#include <string>
using namespace std;

class ItemFactory
{
public:
	// create:			reads from .txt file and creates Items. Depending on item type, creates different items.
	// Preconditions:	file is formatted according to specifications
	// Postconditions:	creates Items depening on item type specified in the file
	static Item* create(istream& stream);

private:
	// createCoin:		private helper method to create coins
	// Preconditions:	file is formatted according to specifications
	// Postconditions:	creates a Coin from the read in file
	static Coin* createCoin(istream& stream);
	
	// createComic:		private helper method to create comics
	// Preconditions:	file is formatted according to specifications
	// Postconditions:	creates a Comic from the read in file
	static Comic* createComic(istream& stream);

	// createSportsCard:	private helper method to create sports cards
	// Preconditions:		file is formatted according to specifications
	// Postconditions:		creates a SportsCard from the read in file
	static SportsCard* createSportsCard(istream& stream);

};
#endif
