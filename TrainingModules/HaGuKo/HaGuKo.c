#include "HaGuKo.h"
#include "../../Console.h"
#include <stdlib.h>
#include <time.h>

void HaGuKo_vPrintMe(void)
{
	int iRand;
	time_t t;

	/* Intializes random number generator */
	srand((unsigned) time(&t));

	iRand = rand() %2;

	/* Add your personal message here */
	if (iRand == 1)
	{
		Console_vPrint("HaGuKo: GIT=Get In Trouble\n");
	}
	else
	{
		Console_vPrint("HaGuKo: GIT=Good In Theory\n");
	}
}
