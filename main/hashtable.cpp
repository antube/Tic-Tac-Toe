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
    //Set a table length of 5
    tableLength = 5;

    //Create a new table of size of table length and assign the pointer to table
    table = new int[tableLength];

    //Run through table and set all slots to negative one
    for(int i = 0; i < tableLength; i++)
        table[i] = -1;

    //Set filled slots to 0
    filledSlots = 0;
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
    for (int i = 0; i < tableLength; i++)
        table[i] = 0;

    //Delete Table
    delete table;

    //Set table length variable to zero
    tableLength = 0;

    //Set filled slots variable to zero
    filledSlots = 0;
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
void hash::addEntry(int entry)
{
    //Set variable hashValue equal to the result of hashFunction with argument of entry
    int hashValue = hashFunction(entry);

    //While the specified position in the hash table is filled
    while(table[hashValue] != -1)
        //If position is not out of bounds
        if(hashValue < tableLength)
            //Add one to hash value
            hashValue++;
        //Else
        else
            //Goto first space in table
            hashValue = 0;
        

    //Set position in hash table equal to entry
    table[hashValue] = entry;

    //Add one to filledSlots counter
    filledSlots++;

    //Check resize of table
    resize();
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
void hash::removeEntry(int entry)
{
    //Assign hash value of entry to variable hashValue
    int hashValue = hashFunction(entry);

    //While table item at hash value is not equal to entry and table item is greater than -1
    while(table[hashValue] != entry && table[hashValue] > -1)
        //hashValue is less than tablelength
        if(hashValue < tableLength)
            //Increment hashvalue
            hashValue++;
        //Else hash value is greater than or equal to table length
        else
            //Set hashValue equal to zero
            hashValue = 0;
        

    int i1 = 1;
    int i2 = 0;

    //while table space is empty
    while(table[hashValue] > -1)
    {
        //Assign value 
        table[hashValue + i2] = table[hashValue + i1];

        //Assign i1 to i2
        i2 = i1;

        //If hashvalue + i1 is less than the length of the table
        if(hashValue + i1 < tableLength)
            //Add one to i1
            i1++;
        else
            //
            i1 = -hashValue;
        
    }

    //Subtract one from filled slots
    filledSlots--;

    //Check if table should be resized and resize it
    resize();
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
bool hash::entryExists(int entry)
{
    //Assign hash value of entry to variable hashValue
    int hashValue = hashFunction(entry);

    //While 
    while(table[hashValue] != entry && table[hashValue] > -1)
        if(hashValue < tableLength)
            hashValue++;
        else
            hashValue = 0;

    if(table[hashValue] != -1)
        return true;

    return false;
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
    //Hash Function entry value multiplied by table length modulus table length
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
void hash::resize()
{
    if (tableLength <= 5)
        return;

    //Create pointer to old Table
    int *oldTable = table;

    //Create copy of old table length
    int oldTableLength = tableLength;

    //Table size increase amount (divide old table length by two and mutliple resulting decimal by old table length)
    int sizeChange = (2 / oldTableLength) * oldTableLength;

    //If table is less then or equal to twenty percent full
    if ((filledSlots / tableLength) % 10 <= 2)
        //Negate sizechange
        sizeChange = -sizeChange;

    //Else if size change is less then seventy percent full
    else if ((filledSlots / tableLength) % 10 < 7)
        //Return without modifiying table
        return;

    //Create new array of int with a size of the length of the old array plus the size change and assign a pointer to it to the main table pointer
    table = new int[oldTableLength + sizeChange];

    //Add size change to table length
    tableLength += sizeChange;

    //Loop through new table setting every location to negative one
    for (int i = 0; i < tableLength; i++)
        table[i] = -1;

    //Loop through the old table adding any elements to the new table and reseting all places to zero
    for (int i = 0; i < oldTableLength; i++)
        if (oldTable[i] > -1)
        {
            add(oldTable[i]);

            oldTable[i] = 0;
        }

    //Delete old table
    delete oldTable;
}