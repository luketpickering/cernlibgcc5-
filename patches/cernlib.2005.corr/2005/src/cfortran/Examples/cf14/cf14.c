/* cf14.c == cf14.C */         /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires cf14_f.f      */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

void Cf14(  int *a, int *b, int *c, int *d, int *e, int *f, int *g, int *h, int *i, int *j, int *k, int *l, int *m, int *n)
  {  *a =  1; *b =  2; *c =  3; *d =  4; *e =  5; *f =  6; *g =  7;
     *h =  8; *i =  9; *j = 10; *k = 11; *l = 12; *m = 13; *n = 14;
     return;}
FCALLSCSUB14(Cf14,CF14,cf14, PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT)


   PROTOCCALLSFSUB14(F14,f14, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT)
#define F14(A,B,C,D,E,F,G,H,I,J,K,L,M,N) \
        CCALLSFSUB14(F14,f14, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, A, B, C, D, E, F, G, H, I, J, K, L, M, N)

main()  {
int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, j=0, k=0, l=0, m=0, n=0;
F14(   a,b,c,d,e,f,g,h,i,j,k,l,m,n);
printf("CF14: %3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d.\n",
       a,b,c,d,e,f,g,h,i,j,k,l,m,n);
return EXIT_SUCCESS;
}
