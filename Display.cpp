//---------------------------------------------------------------------------
// Display.cpp
// Implementation file for Display class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Display Class: child class of Action. Has pure virtual method. Prints out
//                the inventory of the store.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#include "Display.h"

// Destructor:		virtual to deallocate memory allocated in children
// Preconditions:	destructor is virtual in children
// Postconditions:	deallocates stock 
Display::~Display()
{

}

// perform:			performs some action (action different depending on child)
// Preconditions:	children classes implement this pure virtual method
// Postconditions:	inventory of store is printed (coins first, then comics, then sports cards)
void Display::perform(Store* store)
{
	cout << endl << "Display: " << endl;
	cout << store->getCoinTree() << endl;
	cout << store->getComicTree() << endl;
	cout << store->getSportsCardTree() << endl;
}
