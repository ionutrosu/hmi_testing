#include "JanLac.h"
#include "../../Console.h"

void JanLac_vPrintMe(void)
{
	int i,j,n,k;

	n = 10;
    Console_vPrint("\n\n");
    for(i=0;i<n;i++)
    {
       for(j=0;j<n-i;j++)
       {
          Console_vPrint("*");
       }
       for(k=0;k<(2*n-2*j);k++)
       {
           Console_vPrint(" ");
       }
	   for(j=0;j<n-i;j++)
       {
           Console_vPrint("*");
       }
       Console_vPrint("\n");
    }
    for(i=0;i<n;i++)
    {
       for(j=0;j<=i;j++)
       {
            Console_vPrint("*");
       }
       for(k=2*n-2*j;k>0;k--)
       {
            Console_vPrint(" ");
       }
	   for(j=0;j<=i;j++)
       {
           Console_vPrint("*");
       }
       Console_vPrint("\n");
    }
}