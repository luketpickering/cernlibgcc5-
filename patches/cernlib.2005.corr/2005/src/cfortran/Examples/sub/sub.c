/* sub.c == sub.C */           /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires sub_f.f       */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

   PROTOCCALLSFSUB4(FUNARG,funarg, ROUTINE, INT, INT, PINT)
#define FUNARG(F,A,B,C) \
        CCALLSFSUB4(FUNARG,funarg, ROUTINE, INT, INT, PINT, F, A, B, C)

#ifdef __cplusplus
#define Ellipsis ...
#else
#define Ellipsis
#endif

int Cfun(int (*f)(Ellipsis), int a, int b) {int c; f(&a,&b,&c); return c;}
#undef  ROUTINE_1
#define ROUTINE_1  (int (*)(Ellipsis))
FCALLSCFUN3(INT,Cfun,CFUN,cfun, ROUTINE, INT, INT)

main() {
int c;
FUNARG(C_FUNCTION(CFUN,cfun),1,2,c);
printf("\nFUNARG(CFUN,1,2,c) returns with c=%d\n",c);
return EXIT_SUCCESS;
}
