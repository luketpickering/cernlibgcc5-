/* v7.c == v7.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires v7_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

/* DOUBLE_PRECISION, instead of double, is only required for CRAY (not T3E).  */

DOUBLE_PRECISION Cv7(DOUBLE_PRECISION d[2][3][5][7][11][13][1])
{
DOUBLE_PRECISION t=0;
int i,j,k,l,m,n,o;
for (            i=0; i< 2; i++) 
  for (          j=0; j< 3; j++)
    for (        k=0; k< 5; k++) 
      for (      l=0; l< 7; l++) 
        for (    m=0; m<11; m++) 
          for (  n=0; n<13; n++) 
            for (o=0; o< 1; o++) t += d[i][j][k][l][m][n][o];
return t;
}
FCALLSCFUN1(DOUBLE,Cv7,CV7,cv7, DOUBLEVVVVVVV)


PROTOCCALLSFFUN1(DOUBLE,V7,v7,DOUBLEVVVVVVV)
#define V7(D)               CCALLSFFUN1(V7,v7, DOUBLEVVVVVVV, D)

main()
{
/* Original d[2][3][5][7][11][13][17] died a SEGV on DECstation MIPS cc 2.10, 
   just like e.g.             main() {double d[2][3][5][7][11][13][17], t=0;} */

DOUBLE_PRECISION d[2][3][5][7][11][13][1], t=0, r=1, tf;
int i,j,k,l,m,n,o;
for (            i=0; i< 2; i++) 
  for (          j=0; j< 3; j++)
    for (        k=0; k< 5; k++) 
      for (      l=0; l< 7; l++) 
        for (    m=0; m<11; m++) 
          for (  n=0; n<13; n++) 
            for (o=0; o< 1; o++) {
              r /= 2;
              t += r;
              d[i][j][k][l][m][n][o] = r;
            }
tf=V7(d);                         
printf("main() filled array d with a total: %10.9f\n", (double)t );
printf("V7()   returned the value:          %10.9f\n", (double)tf);
return EXIT_SUCCESS;
}                                 /* cast req.d for CRAY -^ */
