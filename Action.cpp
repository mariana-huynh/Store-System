//---------------------------------------------------------------------------
// Action.cpp
// Implementation file for Action class.
// Author: Mariana Huynh
//---------------------------------------------------------------------------
// Action Class: parent class of History, Customer, Display, and Transaction.
//               Has pure virtual method.
// 
// Assumptions: none.
//---------------------------------------------------------------------------

#include "Action.h"

// Destructor:		virtual to deallocate memory allocated in children
// Preconditions:	destructor is virtual in children
// Postconditions:	deallocates any new memory allocated in children
Action::~Action()
{

}
