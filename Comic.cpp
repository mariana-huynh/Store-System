//---------------------------------------------------------------------------
// Comic.cpp
// Implementation file for Comic class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Comic Class: base class of Item. Has pure virtual method. Creates comic 
//             items.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#include "Comic.h"

// Destructor:		virtual, deallocates new memory allocated in child
// Precconditions:	title and publisher exist
// Postconditions:	deallocates title and publisher
Comic::~Comic()
{

}

// printHelper:		called by operator<<, allows for polymorphic behavior of friend operator<<
// Preconditions:	grade, c.grade, type, and c.type are valid strings, year and c.year are valid ints
// Postconditions:	outputs grade, year, and type with a space inbetween each 
ostream& Comic::printHelper(ostream& output) const
{
    cout << "C " << getStock() << " " << getYear() << " " << getGrade() << " " << title << " " << publisher << endl;
    return output;
}

// operator ==:		overloaded equals to operator
// Preconditions:	grade, cRight.grade, title, cRight.title, publisher, and cRight.publisher are valid strings, year and cRight.year are valid ints
// Postconditions:	returns true if this->grade, year, title, and publisher are equal to right.grade, year, title, and publisher. returns 
//                  false if they are not equal to each other.  
bool Comic::operator==(const Item& right) const
{
    const Comic& cRight = static_cast<const Comic&>(right);

    if (getGrade() == cRight.getGrade() && getYear() == cRight.getYear() && title == cRight.title && publisher == cRight.publisher)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// operator <:		overloaded less than operator 
// Preconditions:   grade, cRight.grade, title, cRight.title, publisher, and cRight.publisher are valid strings, year and cRight.year are valid ints
// Postconditions:  returns true if this->grade, year, title, or publisher are less than right.grade, year, title, or publisher. returns 
//                  false if opposite is true.
bool Comic::operator<(const Item& right) const
{
    const Comic& cRight = static_cast<const Comic&>(right);

    if (publisher == cRight.publisher)
    {
        if (title == cRight.title)
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
            return title < cRight.title;
        }
    }
    else
    {
        return publisher < cRight.publisher; 
    }
}

// operator >:		overloaded more than operator 
// Preconditions:   grade, cRight.grade, title, cRight.title, publisher, and cRight.publisher are valid
//                  strings, year and cRight.year are valid ints
// Postconditions:  returns true if this->grade, year, title, or publisher are more than right.grade, year,
//                  title, or publisher. returns false if opposite is true.
bool Comic::operator>(const Item& right) const
{
    const Comic& cRight = static_cast<const Comic&>(right);

    return !(*this < cRight);
}


// getItemType:		pure virtual method
// Preconditions:	methods exists are pure virtual in parent class
// Postconditions:	returns item type
ItemType Comic::getItemType() const
{

    return ItemType::ComicType;    // from enum ItemType

}

// getTitle:		gets the title of the item
// Preconditions:	none
// Postconditions:	returns title
const string& Comic::getTitle() const
{
    return title;
}

// setTitle:		sets the title to t
// Preconditions:	t is a valid string
// Postconditions:	title = t
void Comic::setTitle(const string& t)
{
    title = t;   // assume file formatted correctly
}

// getPublisher:	gets the publisher of the item
// Preconditions:	none
// Postconditions:	returns publisher
const string& Comic::getPublisher() const
{
    return publisher;
}

// setPublisher:	sets the publisher to p
// Preconditions:	p is a valid string
// Postconditions:	publisher = p
void Comic::setPublisher(const string& p)
{
    publisher = p;   // assume file formatted correctly
}