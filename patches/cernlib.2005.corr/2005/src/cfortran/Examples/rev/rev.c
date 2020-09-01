/* rev.c == rev.C */           /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires rev_f.f       */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#include "cfortran.h"


                          PROTOCCALLSFFUN1(INT,FREV,frev, INTV)
#define FREV(A1)               CCALLSFFUN1(    FREV,frev, INTV, A1)
                          PROTOCCALLSFSUB1(REV,rev, INTV)
#define REV(A1)                CCALLSFSUB1(REV,rev, INTV, A1)

main() {
static int a[] = {1,2};
printf("REV(a[0,1]=%d,%d) receives:",a[0],a[1]);
REV(a); printf("a[0,1]=%d,%d\n",a[0],a[1]);
printf("FREV(a[0,1]=%d,%d) receives:",a[0],a[1]);
printf("%d",FREV(a)); printf(" with a[0,1]=%d,%d\n",a[0],a[1]);
return EXIT_SUCCESS;
}
