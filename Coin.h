//---------------------------------------------------------------------------
// Coin.h
// Header file for Coin class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Coin Class: base class of Item. Has pure virtual method. Creates coin 
//             items.
// 
// Assumptions: none.
//
//---------------------------------------------------------------------------

#ifndef Coin_h
#define Coin_h

#include "Item.h"
#include <iostream>

using namespace std;

class Coin : public Item
{
public:
	// Destructor:		virtual, deallocates new memory allocated in child
	// Precconditions:	type exists 
	// Postconditions:	deallocates type
	virtual ~Coin();

	// printHelper:		called by operator<<, allows for polymorphic behavior of friend operator<<
	// Preconditions:	grade, c.grade, type, and c.type are valid strings, year and c.year are valid ints
	// Postconditions:	outputs grade, year, and type with a space inbetween each 
	virtual ostream& printHelper(ostream& output) const;

	// operator ==:		overloaded equals to operator
	// Preconditions:	grade, right.grade, type, and right.type are valid strings, year and right.year are valid ints 
	// Postconditions:	returns true if this->grade, year, and type are equal to right.grade, year, and type. returns 
	//                  false if they are not equal to each other.
	virtual bool operator==(const Item& right) const;

	// operator <:		overloaded less than operator 
	// Preconditions:   grade, right.grade, type, and right.type are valid strings, year and right.year are valid ints 
	// Postconditions:  returns true if this->grade, year, or type are less than right.grade, year, or type. returns 
	//                  false if opposite is true.
	virtual bool operator<(const Item& right) const;

	// operator >:		overloaded more than operator 
	// Preconditions:   grade, right.grade, type, and right.type are valid strings, year and right.year are valid ints 
	// Postconditions:  returns true if this->grade, year, or type are more than right.grade, year, or type. returns 
	//                  false if opposite is true.
	virtual bool operator>(const Item& right) const;

	// getItemType:		pure virtual method
	// Preconditions:	methods exists are pure virtual in parent class
	// Postconditions:	returns item type
	virtual ItemType getItemType() const;

	// getType:		gets the type of the item
	// Preconditions:	none
	// Postconditions:	returns type
	virtual const string& getType() const;

	// setType:			sets the type to t
	// Preconditions:	t is a valid string
	// Postconditions:	type = t
	virtual void setType(const string& t);

private:
	string type;

};
#endif
