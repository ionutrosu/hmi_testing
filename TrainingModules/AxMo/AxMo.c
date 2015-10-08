#include "AxMo.h"
#include "../../Console.h"
#include <stdlib.h>
#include <time.h>

void AxMo_vPrintMe(void)
{
	int iRand = iGetRandNo();

	Console_vPrint("\nAxMo: ");
	switch (iRand) {
		case 1:
			Console_vPrint("Remember: Everything will be fine!");
			break;
		case 2:
			Console_vPrint("Stur laecheln und winken, Maenner!");
			break;
		case 3:
			Console_vPrint("Oh Lord, won't you buy me a Mercedes Benz?");
			break;
		default:
			Console_vPrint("The answer to life, the universe and everything: 213!");
			Console_vPrint("\nAxMo: Remember: Everything will be fine!\nAxMo: Stur laecheln und winken, Maenner!\n");
			break;
	}
	Console_vPrint("\n");
};

int iGetRandNo(void)
{
	int iRet;
    time_t t;

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    iRet = rand() & 0x00000003;
	
	return iRet;
};
