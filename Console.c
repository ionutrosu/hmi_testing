/* EasyCASE V6.5 01.10.2014 13:41:08 */
/* EasyCASE O
If=horizontal
LevelNumbers=no
LineNumbers=no
Colors=16777215,0,12582912,12632256,0,0,0,16711680,8388736,0,33023,32768,0,0,0,0,0,32768,12632256,255,65280,255,255,16711935
ScreenFont=System,,100,1,-13,0,700,0,0,0,0,0,0,1,2,1,34,96,96
PrinterFont=Courier,,100,1,-85,0,400,0,0,0,0,0,0,1,2,1,49,600,600
LastLevelId=4 *///comment
/* EasyCASE ( 1 */
#include <stdio.h>
#include<windows.h>
#include "Console.h"
/*test*/
/* EasyCASE ( 2
   Console_vPrint */
/* EasyCASE F */
void Console_vPrint(char *s)
   {
   printf("%s", s);
   }
/* EasyCASE ) */
/* EasyCASE ( 3
   Console_vWaitForReturn */
/* EasyCASE F */
void Console_vWaitForReturn()
   {
   getchar();
   }
/* EasyCASE ) */
#define std_con_out GetStdHandle(STD_OUTPUT_HANDLE)
/* EasyCASE ( 4
   Console_setcolor */
/* EasyCASE F */
void Console_setcolor(concol textcol,concol backcol)
   {
   textcol%=16;backcol%=16;
   /* EasyCASE : */
      {
      unsigned short wAttributes = ((unsigned short)backcol<<4)|(unsigned short)textcol;
      SetConsoleTextAttribute(std_con_out, wAttributes);
      }
   }
/* EasyCASE ) */
/* EasyCASE ) */
