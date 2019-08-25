class hash
{
    public:
        hash();  //Constructor
        ~hash(); //Destructor

        //Add entry to hash table
        void addEntry( int e ) { add(e); }

        //Remove entry from hash table
        void removeEntry( int e ) { remove(e); }

        //Check if specified entry exists in table
        bool entryExists( int e ) { return exists(e); }

    private:
        int *table;      //Pointer to hash table
        int tableLength; //Length of hashtable

        //Add item to table
        void add( int );

        //Remove item from table
        void remove( int );

        //Check if item exists in hash table
        bool exists( int );

        //Returns hash value
        int hashFunction( int );

        void resize( int )
        {

        }
};