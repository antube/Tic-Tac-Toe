#pragma once

class hash
{
    public:
        hash();  //Constructor
        ~hash(); //Destructor

        //Add entry to hash table
        void add( int e ) { addEntry(e); }

        //Remove entry from hash table
        void remove( int e ) { removeEntry(e); }

        //Check if specified entry exists in table
        bool exists( int e ) { return entryExists(e); }

        int size() { return filledSlots;}

    private:
        int *table;      //Pointer to hash table
        int tableLength; //Length of hashtable
        int filledSlots; //Number of filled slots

        //Add item to table
        void addEntry( int );

        //Remove item from table
        void removeEntry( int );

        //Check if item exists in hash table
        bool entryExists( int );

        //Returns hash value
        int hashFunction( int );

        //Resizes hash table
        void resize();
};