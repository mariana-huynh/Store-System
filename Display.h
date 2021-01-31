//---------------------------------------------------------------------------
// Display.h
// Header file for Display class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Display Class: child class of Action. Has pure virtual method. Prints out
//                the inventory of the store.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#ifndef Display_h
#define Display_h

//#include "Store.h"  // inherited from Action
#include "Action.h"
#include <iostream>

using namespace std;

class Display : public Action 
{
public: 
	// Destructor:		virtual to deallocate memory allocated in children
	// Preconditions:	destructor is virtual in children
	// Postconditions:	deallocates stock 
	virtual ~Display();

	// perform:			performs some action (action different depending on child)
	// Preconditions:	children classes implement this pure virtual method
	// Postconditions:	inventory of store is printed (coins first, then comics, then sports cards)
	virtual void perform(Store* store);

};
#endif
