/* vv.c == vv.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires vv_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

/* FORTRAN_REAL, instead of float, is only required for CRAY T3E.             */
/* DOUBLE_PRECISION, instead of double, is only required for CRAY (not T3E).  */

void Cvv(DOUBLE_PRECISION d[2][2], FORTRAN_REAL f[2][2], int i[2][2])
{
int j,k; double t[2][2];
for (j=0; j<2; j++) for (k=0; k<2; k++) {
  t[j][k] = d[j][k];
  d[j][k] = f[j][k];
  f[j][k] = i[j][k];
  i[j][k] = t[j][k];
}
return;
}
FCALLSCSUB3(Cvv,CVV,cvv, DOUBLEVV, FLOATVV, INTVV)


             PROTOCCALLSFSUB3(VV,vv, DOUBLEVV, FLOATVV, INTVV)
#define VV(D,F,I) CCALLSFSUB3(VV,vv, DOUBLEVV, FLOATVV, INTVV, D, F, I)

main()
{
DOUBLE_PRECISION d[2][2]; 
FORTRAN_REAL     f[2][2];
int              i[2][2];
int j,k;
for (j=0; j<2; j++) for (k=0; k<2; k++) {
  d[j][k] = 100+10*j+k;
  f[j][k] = 200+10*j+k;
  i[j][k] = 300+10*j+k;
}
VV(d,f,i);
                               /*  \/- cast req.d for CRAY. */
printf("%4.0f%4.0f%4.0f%4.0f\n",(double)d[0][0],(double)d[0][1],
                                (double)d[1][0],(double)d[1][1]);
printf("%4.0f%4.0f%4.0f%4.0f\n",f[0][0],f[0][1],f[1][0],f[1][1]);
printf("%4d%4d%4d%4d\n"        ,i[0][0],i[0][1],i[1][0],i[1][1]);
return EXIT_SUCCESS;
}
