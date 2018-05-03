/*
*  0/0 | 1/0 | 2/0
*  ---------------
*  0/1 | 1/1 | 2/1
*  ---------------
*  0/2 | 1/2 | 2/2
*
* Modulus / Division
*
* Modulus:  i % 3
* Division: i / 3
*/

//INCLUDES
#include "definitions.h"
#include "structs.h"

//DEFINTIONS


//PROTOTYPES
position choose(int*, int*, int);



int computer_play(int *bStart, int *bEnd, int player)
{
	position move;
	move.initialization();
	int *p1 = bStart;
	while (bStart <= bEnd)
	{
		if (*bStart == player)
		{

		}
		p1++;
	}

	return 0;
}

position choose(int *bStart, int *bEnd, int Player)
{
	position hello;
	hello.initialization();

	return hello;
}