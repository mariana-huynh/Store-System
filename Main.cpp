//---------------------------------------------------------------------------
// Main.cpp
// Driver code for reading in text files. 
// Author: Mariana Huynh 
//---------------------------------------------------------------------------
// Main: constructs a store and reads in text files. 
//
// Assumptions: all text files are named accordingly and exist in the same 
//              directory as the code and is formatted as described in the
//              specifications.
//---------------------------------------------------------------------------

#include <iostream>
using namespace std;

#include "Store.h"

// main:			makes a store and reads in all three of the files 
// Preconditions:	all text files are named accordingly and exist in the same directory as the code
//                  and is formatted as described in the specifications
// Postconditions:	a store is constructed and the inventory, customer, and command files are read in
int main()
{
	Store collectablesStore;

	collectablesStore.readInventoryList();
	collectablesStore.readCustomerList();
	collectablesStore.readCommandList();

	return 0;
}