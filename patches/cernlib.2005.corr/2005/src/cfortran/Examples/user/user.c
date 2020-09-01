/* user.c == user.C */         /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires user_f.f      */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

/* We define a new type USERINT. [Same functionality as PINT actually.] */

#ifdef OLD_VAXC        /* To avoid %CC-I-PARAMNOTUSED. */
#pragma nostandard
#endif

#define USERINT_cfV(  T,A,B,F)       SIMPLE_cfV(T,A,B,F)
#define USERINT_cfSEP(T,  B)         SIMPLE_cfSEP(T,B)
#define USERINT_cfINT(N,A,B,X,Y,Z)   SIMPLE_cfINT(N,A,B,X,Y,Z)
#define USERINT_cfSTR(N,T,A,B,C,D,E) SIMPLE_cfSTR(N,T,A,B,C,D,E)
#define USERINT_cfCC( T,A,B)         SIMPLE_cfCC(T,A,B)
#define USERINT_cfAA( T,A,B)         USERINT_cfB(T,A)
#define USERINT_cfU(  T,A)           USERINT_cfN(T,A)

#define USERINT_cfN(  T,A)  int *A
#define USERINT_cfB(  T,A)     &(A)

#ifdef OLD_VAXC        /* Have avoided %CC-I-PARAMNOTUSED. */
#pragma standard
#endif

                  PROTOCCALLSFSUB2(EASY,easy, USERINT, INT)
#define EASY(A,B)      CCALLSFSUB2(EASY,easy, USERINT, INT, A, B)

main() {
int a;
printf("\nUsing user defined USERINT argument type.\n");
EASY(a,7);
printf("The FORTRAN routine EASY(a,7) returns a = %d\n", a);
return EXIT_SUCCESS;
}
