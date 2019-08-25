#include "hashtable.h"

///////////////////////
// hash
//
// Arguments:
//     None
//
// Return:
//     None
///////////////////////
hash::hash()
{
    tableLength = 5;
    table = new int[tableLength];
}

///////////////////////
// ~hash
//
// Arguments:
//     None
//
// Return:
//     None
///////////////////////
hash::~hash()
{
    delete table;
    tableLength = 0;
}

///////////////////////
// add
//
// Arguments:
//     entry : int
//
// Return:
//     None
///////////////////////
void hash::add(int entry)
{

}

///////////////////////////
// remove
//
// Arguments:
//     entry : int
//
// Return:
//     None
///////////////////////////
void hash::remove(int entry)
{

}

///////////////////////////
// exists
// 
// Arguments:
//     entry : int
//
// Return:
//     bool : Whether or not the specified value exists in table
///////////////////////////
bool hash::exists(int entry)
{

}

///////////////////////////////
// hashFunction
//
// Arguments:
//     entry : int
//
// Return:
//     int : hash value
///////////////////////////////
int hash::hashFunction(int entry)
{
    return (entry * tableLength) % tableLength; 
}

////////////////////////////
// resize
//
// Arguments:
//     entry : int
//
// Return:
//     None
////////////////////////////
void hash::resize(int entry)
{

}