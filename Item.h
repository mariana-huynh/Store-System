//---------------------------------------------------------------------------
// Item.h
// Header file for Item class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Item Class: parent class of Coin, Comic, and SportsCard. Has pure virtual 
//             method. Similar to Comparable class from Program 2.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#ifndef Item_h
#define Item_h

#include <iostream>
using namespace std;

enum ItemType
{
	CoinType,
	ComicType,
	SportsCardType
};

class Item
{	
public:
	// Destructor:		virtual method for polymorphic behavior
	// Preconditions:	year and grade exist
	// Postconditions:	deallocates memory associated with grade and year
	virtual ~Item();

	// operator <<:		overloaded insertion operator 
	// Preconditions:	grade and right.grade are valid strings, year and right.year are valid ints
	// Postconditions:	outputs grade and year with a space inbetween 
	friend ostream& operator<<(ostream& output, const Item& item);

	// printHelper:		called by operator<<, allows for polymorphic behavior of friend operator<<
	// Preconditions:	grade and right.grade are valid strings, year and right.year are valid ints
	// Postconditions:	outputs grade and year with a space inbetween 
	virtual ostream& printHelper(ostream& output) const;

	// operator ==:		overloaded equals to operator
	// Preconditions:	grade and right.grade are valid strings, year and right.year are valid ints 
	// Postconditions:	returns true if this->grade and year are equal to right.grade and year, returns 
	//                  false if they are not equal to each other  
	virtual bool operator==(const Item& right) const;

	// operator <:		overloaded less than operator 
	// Preconditions:   grade and right.grade are valid strings, year and right.year are valid ints 
	// Postconditions:  returns true if this->grade or year are less than right.grade or year, returns 
	//                  false if opposite is true
	virtual bool operator<(const Item& right) const;

	// operator >:		overloaded more than operator 
	// Preconditions:   grade and right.grade are valid strings, year and right.year are valid ints 
	// Postconditions:  returns true if this->grade or year are more than right.grade or year, returns 
	//                  false if opposite is true
	virtual bool operator>(const Item& right) const;

	 // getGrade:		gets the grade of the item
	 // Preconditions:	none
	 // Postconditions:	returns grade
	 virtual const string& getGrade() const;

	 // setGrade:		sets the grade to g
	 // Preconditions:	g is a valid string
	 // Postconditions:	grade = g
	 virtual void setGrade(const string& g);

	 // getYear:			gets the year of the item
	 // Preconditions:	none 
	 // Postconditions:	returns year
	 virtual const int getYear() const;

	 // setYear:			sets the year to y
	 // Preconditions:	y is a valid int 
	 // Postconditions:	year = y
	 virtual void setYear(const int y);

	 // getStock:		gets the stock of the store 
	// Preconditions:	stock is a valid int
	// Postconditions:	stock is returned
	 virtual int getStock() const;

	 // setStock:		sets stock to s
	 // Preconditions:	s is a valid int 
	 // Postconditions:	stock = s
	 virtual void setStock(int s);

	 // increaseStock:	adds value add to stock value
	 // Preconditions:	add is a valid int
	 // Postconditions:	stock += add
	 virtual void increaseStock(int add);

	 // decreaseStock:	decreases value of stock by one unit
	 // Preconditions:	stock is greater than 0
	 // Postconditions:	stock is decremented one value
	 virtual void decreaseStock();

	 // getItemType:	pure virtual method
	 // Preconditions:	children implement this method
	 // Postconditions: see children class
	 virtual ItemType getItemType() const = 0;

private:
	string grade;
	int year;
	int stock;
};
#endif
