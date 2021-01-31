//---------------------------------------------------------------------------
// Comic.h
// Header file for Comic class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Comic Class: base class of Item. Has pure virtual method. Creates comic 
//             items.
// 
// Assumptions: none. 
//---------------------------------------------------------------------------

#ifndef Comic_h
#define Comic_h

#include "Item.h"
#include <iostream>

using namespace std;

class Comic : public Item
{
public:
	// Destructor:		virtual, deallocates new memory allocated in child
	// Precconditions:	title and publisher exist
	// Postconditions:	deallocates title and publisher
	virtual ~Comic();

	// printHelper:		called by operator<<, allows for polymorphic behavior of friend operator<<
	// Preconditions:	grade, c.grade, title, c.title, publisher, and c.publisher are valid strings, 
	//                  year and c.year are valid ints
	// Postconditions:	outputs grade, year, title, and publisher with a space inbetween each 
	virtual ostream& printHelper(ostream& output) const;

	// operator ==:		overloaded equals to operator
	// Preconditions:	grade, cRight.grade, title, cRight.title, publisher, and cRight.publisher are valid 
	//                  strings, year and cRight.year are valid ints
	// Postconditions:	returns true if this->grade, year, title, and publisher are equal to right.grade, year, 
	//                  title, and publisher. returns false if they are not equal to each other.
	virtual bool operator==(const Item& right) const;

	// operator <:		overloaded less than operator 
	// Preconditions:   grade, cRight.grade, title, cRight.title, publisher, and cRight.publisher are valid
	//                  strings, year and cRight.year are valid ints
	// Postconditions:  returns true if this->grade, year, title, or publisher are less than right.grade, year,
	//                  title, or publisher. returns false if opposite is true.
	virtual bool operator<(const Item& right) const;

	// operator >:		overloaded more than operator 
	// Preconditions:   grade, cRight.grade, title, cRight.title, publisher, and cRight.publisher are valid
	//                  strings, year and cRight.year are valid ints
	// Postconditions:  returns true if this->grade, year, title, or publisher are more than right.grade, year,
	//                  title, or publisher. returns false if opposite is true.
	virtual bool operator>(const Item& right) const;

	// getItemType:		pure virtual method
	// Preconditions:	methods exists are pure virtual in parent class
	// Postconditions:	returns item type
	virtual ItemType getItemType() const;

	// getTitle:		gets the title of the item
	// Preconditions:	none
	// Postconditions:	returns title
	virtual const string& getTitle() const;

	// setTitle:		sets the title to t
	// Preconditions:	t is a valid string
	// Postconditions:	title = t
	virtual void setTitle(const string& t);

	// getPublisher:	gets the publisher of the item
	// Preconditions:	none
	// Postconditions:	returns publisher
	virtual const string& getPublisher() const;

	// setPublisher:	sets the publisher to p
	// Preconditions:	p is a valid string
	// Postconditions:	publisher = p
	virtual void setPublisher(const string& p);

private:
	string title;
	string publisher;

};
#endif
