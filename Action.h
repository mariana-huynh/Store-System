//---------------------------------------------------------------------------
// Action.h
// Header file for Action class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Action Class: parent class of History, Customer, Display, and Transaction.
//               Has pure virtual method. 
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#ifndef Action_h
#define Action_h

#include "Store.h"

class Action
{
public:
	// Destructor:		virtual to deallocate memory allocated in children
	// Preconditions:	destructor is virtual in children
	// Postconditions:	deallocates any new memory allocated in children
	virtual ~Action();

	// perform:			performs some action (action different depending on child)
	// Preconditions:	children classes implement this pure virtual method
	// Postconditions:	action is performed (varies depending on children)
	virtual void perform(Store* store) = 0;

}; 
#endif

