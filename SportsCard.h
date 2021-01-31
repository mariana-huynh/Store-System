//---------------------------------------------------------------------------
// SportsCard.h
// Header file for SportsCard class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// SportsCard Class: base class of Item. Has pure virtual method. Creates 
//                   sports card items.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#ifndef SportsCard_h
#define SportsCard_h

#include "Item.h"
#include <iostream>
using namespace std;

class SportsCard : public Item
{
public:
	// Destructor:		virtual, deallocates new memory allocated in child
	// Precconditions:	title and publisher exist
	// Postconditions:	deallocates manufacturer and player
	virtual ~SportsCard();

	// printHelper:		called by operator<<, allows for polymorphic behavior of friend operator<<
	// Preconditions:	grade, c.grade, manufacturer, c.manufacturer, player, and c.player are valid
	//                  strings, year and c.year are valid ints
	// Postconditions:	outputs grade, year, manufacturer, and player with a space inbetween each 
	virtual ostream& printHelper(ostream& output) const;

	// operator ==:		overloaded equals to operator
	// Preconditions:	grade, cRight.grade, manufacturer, cRight.manufacturer, player, and cRight.player 
	//                  are valid strings, year and cRight.year are valid ints
	// Postconditions:	returns true if this->grade, year, manufacturer, and player are equal to right.grade,
	//                  year, manufacturer, and player. returns false if they are not equal to each other.                   
	virtual bool operator==(const Item& right) const;

	// operator <:		overloaded less than operator 
	// Preconditions:   grade, cRight.grade, manufacturer, cRight.manufacturer, player, and cRight.player 
	//                  are valid strings, year and cRight.year are valid ints
	// Postconditions:  returns true if this->grade, year, manufacturer, or player are less than right.grade,
	//                  year, manufacturer, or player. returns false if opposite is true.              
	virtual bool operator<(const Item& right) const;

	// operator >:		overloaded more than operator 
	// Preconditions:   grade, cRight.grade, manufacturer, cRight.manufacturer, player, and cRight.player 
	//                  are valid strings, year and cRight.year are valid ints
	// Postconditions:  returns true if this->grade, year, manufacturer, or player are more than right.grade,
	//                  year, manufacturer, or player. returns false if opposite is true.  
	virtual bool operator>(const Item& right) const;

	// getItemType:		pure virtual method
	// Preconditions:	methods exists are pure virtual in parent class
	// Postconditions:	returns item type
	virtual ItemType getItemType() const;

	// getManufacturer:	gets the manufacturer of the item
	// Preconditions:	none
	// Postconditions:	returns manufacturer
	virtual const string& getManufacturer() const;

	// setManufacturer:	sets the manufacturer to m
	// Preconditions:	m is a valid string
	// Postconditions:	manufacturer = m
	virtual void setManufacturer(const string& m);

	// getPlayer:		gets the player of the item
	// Preconditions:	none
	// Postconditions:	returns player
	virtual const string& getPlayer() const;

	// setPlayer:		sets the player to p
	// Preconditions:	p is a valid string
	// Postconditions:	player = p
	virtual void setPlayer(const string& p);

private:
	string manufacturer;
	string player;

};
#endif


