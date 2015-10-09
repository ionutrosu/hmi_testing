/* EasyCASE V6.5 02.10.2014 13:45:13 */
/* EasyCASE O
If=horizontal
LevelNumbers=no// comment
LineNumbers=no
Colors=16777215,0,12582912,12632256,0,0,0,16711680,8388736,0,33023,32768,0,0,0,0,0,32768,12632256,255,65280,255,255,16711935
ScreenFont=System,,100,1,-13,0,700,0,0,0,0,0,0,1,2,1,34,96,96
PrinterFont=Courier,,100,1,-85,0,400,0,0,0,0,0,0,1,2,1,49,600,600
LastLevelId=1 */
/* EasyCASE ( 1 */
/* EasyCASE < */
#ifndef CONSOLE_H
#define CONSOLE_H

void    Console_vPrint();
void    Console_vWaitForReturn();

typedef enum concol
{
        black=0,
        dark_blue=1,
        dark_green=2,
        dark_aqua,dark_cyan=3,
        dark_red=4,
        dark_purple=5,dark_pink=5,dark_magenta=5,
        dark_yellow=6,
        dark_white=7,
        gray=8,
        blue=9,
        green=10,
        aqua=11,cyan=11,
        red=12,
        purple=13,pink=13,magenta=13,
        yellow=14,
        white=15
}concol;
// cooment
void Console_setcolor(concol textcolor,concol backcolor);


/* test */

/* another test*/
/* test test test */


#endif
/* EasyCASE > */
/* EasyCASE ) */
