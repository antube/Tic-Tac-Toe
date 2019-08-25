#include "movetype.h"

class move
{
    public:
        move();  //Constructor
        ~move(); //Destructor

        //Get position by returning value
        int getposition() { return position; }

        //Get position by setting provided variable equal to position
        void getposition(int &p) { p = position; }

        //Set position by pass by value
        void setPosition(int p) { position = p; }

        //Get move type by returning value
        MoveType getType() { return type; }

        //Get move type by setting provided variable equal to type
        void getType(MoveType &mt) { mt = type; }

        //Set type by pass by value
        void setType(MoveType mt) { type = mt; }

        //Get value by returning int
        int getValue() { return value; }

        //Get value by passing a reference argument
        void getValue(int &v) { v = value; }

        //Set value
        void setValue(int v) { value = v; }

        //Allow for plus plus operator to be used on class
        void operator++() { value++; }

        //Allow for plus equals operator to be used on class
        void operator+=(int v) { value += v; }

        //Allow for minus minus operator to be used on class
        void operator--() { value--; }

        //Allow for minus equals operator to be used on class
        void operator-=(int v) { value -= v; }

        //Allow for equal operator to be used on class
        void operator=(move &m1);

    private:
        int position; //Position on board
        MoveType type; //Type of move stored
        int value; //Statistical value on position
};
