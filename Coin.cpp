//---------------------------------------------------------------------------
// Coin.cpp
// Implementation file for Coin class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Coin Class: base class of Item. Has pure virtual method. Creates coin 
//             items.
// 
// Assumptions: none.
//
//---------------------------------------------------------------------------

#include "Coin.h"

// Destructor:		virtual, deallocates new memory allocated in child
// Precconditions:	type exists 
// Postconditions:	deallocates type
Coin::~Coin()
{

}

// printHelper:		called by operator<<, allows for polymorphic behavior of friend operator<<
// Preconditions:	grade, c.grade, type, and c.type are valid strings, year and c.year are valid ints
// Postconditions:	outputs grade, year, and type with a space inbetween each 
ostream& Coin::printHelper(ostream& output) const
{
    cout << "M " << getStock() << " " << getYear() << " " << getGrade() << " " << type << endl;
    return output;
}

// operator ==:		overloaded equals to operator
// Preconditions:	grade, right.grade, type, and right.type are valid strings, year and right.year are valid ints 
// Postconditions:	returns true if this->grade, year, and type are equal to right.grade, year, and type. returns 
//                  false if they are not equal to each other.
bool Coin::operator==(const Item& right) const
{
    const Coin& cRight = static_cast<const Coin&>(right);

    if (getGrade() == cRight.getGrade() && getYear() == cRight.getYear() && type == cRight.type)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// operator <:		overloaded less than operator 
// Preconditions:   grade, right.grade, type, and right.type are valid strings, year and right.year are valid ints 
// Postconditions:  returns true if this->grade, year, or type are less than right.grade, year, or type. returns 
//                  false if opposite is true.
bool Coin::operator<(const Item& right) const
{
    const Coin& cRight = static_cast<const Coin&>(right);

    if (type == cRight.type)
    {
        if (getYear() == cRight.getYear())
        {
            return getGrade() < cRight.getGrade();
        }
        else
        {
            return getYear() < cRight.getYear();
        }
    }
    else
    {
        return type < cRight.type;
    }
}

// operator >:		overloaded more than operator 
// Preconditions:   grade, right.grade, type, and right.type are valid strings, year and right.year are valid ints 
// Postconditions:  returns true if this->grade, year, or type are more than right.grade, year, or type. returns 
//                  false if opposite is true.
bool Coin::operator>(const Item& right) const
{
    const Coin& cRight = static_cast<const Coin&>(right);

    return !(*this < cRight);
}


// getItemType:		pure virtual method
// Preconditions:	methods exists are pure virtual in parent class
// Postconditions:	returns item type
ItemType Coin::getItemType() const
{
    return ItemType::CoinType;    // from enum ItemType 
}

// getType:		gets the type of the item
// Preconditions:	none
// Postconditions:	returns type
const string& Coin::getType() const
{
    return type;
}

// setType:		sets the type to t
// Preconditions:	t is a valid string
// Postconditions:	type = t
void Coin::setType(const string& t)
{
    type = t;    // assume file formatted correctly
}
