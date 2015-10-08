/* EasyCASE V6.5 09/16/2014 17:50:30 */
/* EasyCASE O
If=horizontal
LevelNumbers=no
LineNumbers=no
Colors=16777215,0,12582912,12632256,0,0,0,16711680,8388736,0,33023,32768,0,0,0,0,0,32768,12632256,255,65280,255,255,16711935
ScreenFont=System,,100,1,-16,0,700,0,0,0,0,0,0,1,2,1,34,120,120
PrinterFont=Courier,,100,1,-85,0,400,0,0,0,0,0,0,1,2,1,49,600,600
LastLevelId=2 */
/* EasyCASE ( 1 */
#include "CriHog.h"
#include "../../Console.h"
#include <stdlib.h>
/* EasyCASE ( 2
   CriHog_vPrintMe */
/* EasyCASE F */
void CriHog_vPrintMe(void)
   {
   int iRand;
   time_t t;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));
   
   iRand = rand() %2;
   
   /* Add your personal message here */
   if (iRand == 1)
      {
      Console_vPrint("CriHog: GIT = Get In Trouble\n");
      /* EasyCASE - */
      /* Comment as a fix */
      }
   else
      {
      Console_vPrint("CriHog: GIT = Good In Theory\n");
      }
   }
/* EasyCASE ) */
/* EasyCASE ) */
