//---------------------------------------------------------------------------
// Item.cpp
// Implementation file for Item class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Item Class: parent class of Coin, Comic, and SportsCard. Has pure virtual 
//             method. Similar to Comparable class from Program 2.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#include "Item.h"

// Destructor:		virtual method for polymorphic behavior
// Preconditions:	year and grade exist
// Postconditions:	deallocates memory associated with grade and year
Item::~Item()
{

}

// operator ==:		overloaded equals to operator
// Preconditions:	grade and right.grade are valid strings, year and right.year are valid ints 
// Postconditions:	returns true if this->grade and year are equal to right.grade and year, returns 
//                  false if they are not equal to each other  
bool Item::operator==(const Item& right) const
{
	if (grade == right.grade && year == right.year)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// operator <:		overloaded less than operator 
// Preconditions:   grade and right.grade are valid strings, year and right.year are valid ints 
// Postconditions:  returns true if this->grade or year are less than right.grade or year, returns 
//                  false if opposite is true
bool Item::operator<(const Item& right) const
{
	if (grade > right.grade)
	{
		return false;
	}
	else if (year > right.year)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// operator >:		overloaded more than operator 
// Preconditions:   grade and right.grade are valid strings, year and right.year are valid ints 
// Postconditions:  returns true if this->grade or year are more than right.grade or year, returns 
//                  false if opposite is true
bool Item::operator>(const Item& right) const
{
	return !(*this < right);
}

// operator <<:		overloaded insertion operator 
// Preconditions:	grade and right.grade are valid strings, year and right.year are valid ints
// Postconditions:	outputs grade and year with a space inbetween 
ostream& operator<<(ostream& output, const Item& item)
{
	return item.printHelper(output);
}

// printHelper:		called by operator<<, allows for polymorphic behavior of friend operator<<
// Preconditions:	grade and right.grade are valid strings, year and right.year are valid ints
// Postconditions:	outputs grade and year with a space inbetween 
ostream& Item::printHelper(ostream& output) const
{
	cout << grade << " " << year << endl;
	return output;
}

// getGrade:		gets the grade of the item
// Preconditions:	none
// Postconditions:	returns grade
const string& Item::getGrade() const
{
	return grade;
}

// setGrade:		sets the grade to g
// Preconditions:	g is a valid string
// Postconditions:	grade = g
void Item::setGrade(const string& g)
{
	grade = g;   // assume file formatted correctly
}

// getYear:			gets the year of the item
// Preconditions:	none 
// Postconditions:	returns year
const int Item::getYear() const
{
	if (year >= 0 && year <= 2020)
	{
		return year;
	}
	else
	{
		return -1;
	}
}

// setYear:			sets the year to y
// Preconditions:	y is a valid int 
// Postconditions:	year = y
void Item::setYear(const int y)
{
	if (y >= 0 && y <= 2020)
	{
		year = y;
	}
}

// getStock:		gets the stock of the store 
// Preconditions:	stock is a valid int
// Postconditions:	stock is returned
int Item::getStock() const
{
	if (stock >= 0)
	{
		return stock;
	}
	else
	{
		return -1;
	}
}

// setStock:		sets stock to s
// Preconditions:	s is a valid int 
// Postconditions:	stock = s
void Item::setStock(int s)
{
	if (s >= 0)
	{
		stock = s;
	}
}

// increaseStock:	adds value add to stock value
// Preconditions:	add is a valid int
// Postconditions:	stock += add
void Item::increaseStock(int add)
{
	if (add >= 0)
	{
		stock += add;
	}
}

// decreaseStock:	decreases value of stock by one unit
// Preconditions:	stock is greater than 0
// Postconditions:	stock is decremented one value
void Item::decreaseStock()
{
	if (stock > 0)
	{
		stock--;
	}
}

