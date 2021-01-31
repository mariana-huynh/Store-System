//---------------------------------------------------------------------------
// SportsCard.cpp
// Implementation file for SportsCard class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// SportsCard Class: base class of Item. Has pure virtual method. Creates 
//                   sports card items.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#include "SportsCard.h"

// Destructor:		virtual, deallocates new memory allocated in child
// Precconditions:	title and publisher exist
// Postconditions:	deallocates manufacturer and player
SportsCard::~SportsCard()
{

}

// printHelper:		called by operator<<, allows for polymorphic behavior of friend operator<<
// Preconditions:	grade, c.grade, type, and c.type are valid strings, year and c.year are valid ints
// Postconditions:	outputs grade, year, and type with a space inbetween each 
ostream& SportsCard::printHelper(ostream& output) const
{
    cout << "S " << getStock() << " " << getYear() << " " << getGrade() << " " << player << " " << manufacturer << endl;
    return output;
}

// operator ==:		overloaded equals to operator
// Preconditions:	grade, sRight.grade, manufacturer, sRight.manufacturer, player, and sRight.player 
//                  are valid strings, year and sRight.year are valid ints
// Postconditions:	returns true if this->grade, year, manufacturer, and player are equal to sRight.grade,
//                  year, manufacturer, and player. returns false if they are not equal to each other.                   
bool SportsCard::operator==(const Item& right) const
{
    const SportsCard& sRight = static_cast<const SportsCard&>(right);

    if (manufacturer == sRight.manufacturer && getYear() == sRight.getYear() && player == sRight.player && getGrade() == sRight.getGrade())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// operator <:		overloaded less than operator 
// Preconditions:   grade, sRight.grade, manufacturer, sRight.manufacturer, player, and sRight.player 
//                  are valid strings, year and sRight.year are valid ints
// Postconditions:  returns true if this->grade, year, manufacturer, or player are less than sRight.grade,
//                  year, manufacturer, or player. returns false if opposite is true.              
bool SportsCard::operator<(const Item& right) const
{
    const SportsCard& sRight = static_cast<const SportsCard&>(right);

    if (player == sRight.player)
    {
        if (getYear() == sRight.getYear())
        {
            if (manufacturer == sRight.manufacturer)
            {
                return getGrade() < sRight.getGrade();
            }
            else
            {
                return manufacturer < sRight.manufacturer;
            }
        }
        else
        {
            return getYear() < sRight.getYear();
        }
    }
    else
    {
        return player < sRight.player;
    }
}

// operator >:		overloaded more than operator 
// Preconditions:   grade, cRight.grade, manufacturer, cRight.manufacturer, player, and cRight.player 
//                  are valid strings, year and cRight.year are valid ints
// Postconditions:  returns true if this->grade, year, manufacturer, or player are more than right.grade,
//                  year, manufacturer, or player. returns false if opposite is true.  
bool SportsCard::operator>(const Item& right) const
{
    const SportsCard& sRight = static_cast<const SportsCard&>(right);

    return !(*this < sRight);
}

// getItemType:		pure virtual method
// Preconditions:	methods exists are pure virtual in parent class
// Postconditions:	returns item type
ItemType SportsCard::getItemType() const
{
    return ItemType::SportsCardType;    // from enum ItemType
}

// getManufacturer:	gets the manufacturer of the item
// Preconditions:	none
// Postconditions:	returns manufacturer
const string& SportsCard::getManufacturer() const
{
    return manufacturer;
}

// setManufacturer:	sets the manufacturer to m
// Preconditions:	m is a valid string
// Postconditions:	manufacturer = m
void SportsCard::setManufacturer(const string& m)
{
    manufacturer = m;   // assume file formatted correctly
}

// getPlayer:		gets the player of the item
// Preconditions:	none
// Postconditions:	returns player
const string& SportsCard::getPlayer() const
{
    return player;
}

// setPlayer:		sets the player to p
// Preconditions:	p is a valid string
// Postconditions:	player = p
void SportsCard::setPlayer(const string& p)
{
    player = p;   // assume file formatted correctly
}