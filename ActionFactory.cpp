//---------------------------------------------------------------------------
// ActionFactory.cpp 
// Implementation file for ActionFactory class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// ActionFactory Class: reads data from the .txt file and creates Actions.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#include "ActionFactory.h"

// create:			reads from file and creates actions
// Preconditions:	file is formatted according to specifications
// Postconditions:	actions are created from read in file
Action* ActionFactory::create(istream& stream, Store* store)
{
	char actionType;
	stream >> actionType;

	if (stream.fail())
	{
		return NULL;
	}

	Action* action;

	if (actionType == 'D')
	{
		action = reinterpret_cast<Action*>(createDisplay(stream, store));
	}
	else if (actionType == 'H')
	{
		action = reinterpret_cast<Action*>(createHistory(stream, store));
	}
	else if (actionType == 'S')
	{
		action = reinterpret_cast<Action*>(createSell(stream, store));
	}
	else if (actionType == 'B')
	{
		action = reinterpret_cast<Action*>(createBuy(stream, store));
	}
	else if (actionType == 'C')
	{
		action = reinterpret_cast<Action*>(createCustomer(stream, store));
	}
	else
	{
		cerr << "Invalid action type: " << actionType << endl;
		stream.ignore(256, '\n');
		return nullptr;
	}

	return action;
}

// createDisplay:	creates Display (which prints out the inventory)
// Preconditions:	file is formatted according to specifications
// Postconditions:	returns newly constructed Display
Display* ActionFactory::createDisplay(istream& stream, Store* store)
{
	return new Display();
}

// createHistory:	creates a history for a customer
// Preconditions:	file is formatted according to specifications
// Postconditions:	new History is constructed 
History* ActionFactory::createHistory(istream& stream, Store* store)
{
	return new History();

}

// createSell:		creates Sell transaction
// Preconditions:	file is formatted according to specifications
// Postconditions:	creates Sell transaction for customer with read in customer ID
Sell* ActionFactory::createSell(istream& stream, Store* store)
{
	stream.ignore(2, ',');
	int customerID = 0;
	string temp;
	getline(stream, temp, ',');
	customerID = std::stoi(temp, nullptr);

	Item* item = findItem(stream, store);

	if (item == nullptr)
	{
		return nullptr;
	}

	Sell* sell = new Sell();
	sell->setItem(item);
	sell->setCustomerID(customerID);

	return sell;
}

// createBuy:		creates Buy transaction
// Preconditions:	file is formatted according to specifications
// Postconditions:	creates Buy transaction for customer with read in customer ID
Buy* ActionFactory::createBuy(istream& stream, Store* store)
{
	stream.ignore(2, ',');
	int customerID = 0;
	string temp;
	getline(stream, temp, ',');
	customerID = std::stoi(temp, nullptr);

	Item* item = findItem(stream, store);

	if (item == nullptr)
	{
		return nullptr;
	}

	Buy* buy = new Buy();
	buy->setItem(item);
	buy->setCustomerID(customerID);

	return buy;
}

// createCustomer:	creates Customer
// Preconditions:	file is formatted according to specifications
// Postconditions:	creates Customer with read in customer ID
Customer* ActionFactory::createCustomer(istream& stream, Store* store)
{
	// different Customer pointers
	// return customer already made when read in customer file
	stream.ignore(2, ',');
	int customerID = 0;
	string temp;
	getline(stream, temp, '\n');
	customerID = std::stoi(temp, nullptr);

	Customer* customer = store->getCustomers().getItem(customerID);

	return customer;
}

// findItem:		finds an Item according to read in file
// Preconditions:	file is formatted according to specifications
// Postconditions:	finds an Item of type specified by char in read in file
Item* ActionFactory::findItem(istream& stream, Store* store)
{
	char itemType;
	stream >> itemType;
	stream.ignore();

	if (itemType == 'M')
	{
		return findCoin(stream, store);
	}
	else if (itemType == 'C')
	{
		return findComic(stream, store);
	}
	else if (itemType == 'S')
	{
		return findSportsCard(stream, store);
	}
	else
	{
		/*cerr << "Invalid item type: " << itemType << endl;*/
		cerr << "Invalid item type: " << itemType << endl;
		stream.ignore(256, '\n');
		return nullptr;
	}
}

// findCoin:		finds item of type Coin
// Preconditions:	file is formatted according to specifications
// Postconditions:	returns the Coin if exists in coinTree
Coin* ActionFactory::findCoin(istream& stream, Store* store)
{
	int year;
	stream >> year;

	stream.ignore(1, ',');
	string grade;
	getline(stream >> ws, grade, ',');

	string type;
	getline(stream >> ws, type, '\n');

	Coin coinToSearch;
	coinToSearch.setYear(year);
	coinToSearch.setGrade(grade);
	coinToSearch.setType(type);

	Coin* found = static_cast<Coin*>(store->getCoinTree().retrieve(coinToSearch));
	store->getCoinTree().retrieve(coinToSearch);

	if (found == nullptr)
	{
		cerr << "Invalid Coin: " << year << " " << grade << " " << type << endl;
		return nullptr;
	}

	return found;
}

// findComic:		finds item of type Comic
// Preconditions:	file is formatted according to specifications
// Postconditions:	returns the Comic if exists in comicTree
Comic* ActionFactory::findComic(istream& stream, Store* store)
{
	int year;
	stream >> year;

	stream.ignore(1, ',');
	string grade;
	getline(stream >> ws, grade, ',');

	string title;
	getline(stream >> ws, title, '\n');

	string publisher;
	getline(stream >> ws, publisher, '\n');

	Comic comicToSearch;
	comicToSearch.setYear(year);
	comicToSearch.setGrade(grade);
	comicToSearch.setTitle(title);
	comicToSearch.setPublisher(publisher);

	Comic* found = static_cast<Comic*>(store->getComicTree().retrieve(comicToSearch));

	if (found == nullptr)
	{
		cerr << "Invalid Comic: " << year << " " << grade << " " << title << publisher << endl;
		return nullptr;
	}

	return found;
}

// findSportsCard:	finds item of type SportsCard
// Preconditions:	file is formatted according to specifications
// Postconditions:	returns the SportsCard if exists in sportsCardTree
SportsCard* ActionFactory::findSportsCard(istream& stream, Store* store)
{
	stream.ignore();
	int year;
	stream >> year;

	stream.ignore(1, ',');
	string grade;
	getline(stream >> ws, grade, ',');

	string player;
	getline(stream >> ws, player, ',');

	string manufacturer;
	getline(stream >> ws, manufacturer, '\n');

	SportsCard scToSearch;
	scToSearch.setYear(year);
	scToSearch.setGrade(grade);
	scToSearch.setPlayer(player);
	scToSearch.setManufacturer(manufacturer);

	SportsCard* found = static_cast<SportsCard*>(store->getSportsCardTree().retrieve(scToSearch));

	if (found == nullptr)
	{
		cerr << "Invalid SportsCard: " << year << " " << grade << " " << player << manufacturer << endl;
		return nullptr;
	}

	return found;
}
