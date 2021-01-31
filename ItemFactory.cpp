//---------------------------------------------------------------------------
// ItemFactory.cpp
// Implementation file for ItemFactory class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// ItemFactory Class: reads data from the .txt file and creates Items.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#include "ItemFactory.h"

// create:			reads from .txt file and creates Items. Depending on item type, creates different items.
// Preconditions:	file is formatted according to specifications
// Postconditions:	creates Items depening on item type specified in the file
Item* ItemFactory::create(istream& stream)
{
	char itemType;
	int itemStock;
	string itemGrade;
	int itemYear;
	Item* item;

	stream >> itemType;

	if (stream.fail())
	{
		return NULL;
	}

	stream.ignore();
	stream >> itemStock;
	stream.ignore();
	stream >> itemYear;
	stream.ignore();
	getline(stream >> ws, itemGrade, ',');

	if (itemType == 'M')
	{
		item = createCoin(stream);
	}
	else if (itemType == 'C')
	{
		item = createComic(stream);
	}
	else if (itemType == 'S')
	{
		item = createSportsCard(stream);
	}
	else
	{
		cerr << "Invalid item type " << itemType << endl;
		stream.ignore(256, '\n');
		return nullptr;
	}

	item->setYear(itemYear);
	item->setGrade(itemGrade);
	item->setStock(itemStock);
	
	return item;
}

// createCoin:		private helper method to create coins
// Preconditions:	file is formatted according to specifications
// Postconditions:	creates a Coin from the read in file
Coin* ItemFactory::createCoin(istream& stream)
{
	string coinType;
	getline(stream >> ws, coinType, '\n');

	Coin* coin = new Coin();
	coin->setType(coinType);
	
	return coin;
}

// createComic:		private helper method to create comics
// Preconditions:	file is formatted according to specifications
// Postconditions:	creates a Comic from the read in file
Comic* ItemFactory::createComic(istream& stream)
{
	string comicTitle;
	string comicPublisher;
	getline(stream >> ws, comicTitle, ',');
	getline(stream >> ws, comicPublisher, '\n');

	Comic* comic = new Comic();
	comic->setPublisher(comicPublisher);
	comic->setTitle(comicTitle);

	return comic;
}

// createSportsCard:	private helper method to create sports cards
// Preconditions:		file is formatted according to specifications
// Postconditions:		creates a SportsCard from the read in file
SportsCard* ItemFactory::createSportsCard(istream& stream)
{
	string scPlayer;
	string scManufacturer;
	getline(stream >> ws, scPlayer, ',');
	getline(stream >> ws, scManufacturer, '\n');

	SportsCard* sportsCard = new SportsCard();
	sportsCard->setManufacturer(scManufacturer);
	sportsCard->setPlayer(scPlayer);

	return sportsCard;
}
