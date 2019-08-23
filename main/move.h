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

        //
        int getValue() { return value; }

        //
        void getValue(int &v) { v = value; }

        //
        void setValue(int v) { value = v; }

        //
        void operator++() { value++; }

        //
        void operator--() { value--; }

        //
        void operator=(move &m1);

    private:
        int position;

        MoveType type;

        int value;
};
