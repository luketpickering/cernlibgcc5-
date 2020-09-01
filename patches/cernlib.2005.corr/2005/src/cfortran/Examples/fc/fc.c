/* fc.c == fc.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fc_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

/* The next 2 lines tell cfortran.h that for the subsequent FCALLSCSUBn
 *  and FCALLSCSUBn declarations, FORTRAN entry points to C routines have the 
 *  C name prefaced with the characters 'CF'.
 */
#undef  fcallsc
#define fcallsc(UN,LN) preface_fcallsc(CF,cf,UN,LN)

void cc(char *s) {printf("cc: had string argument:%s.\n",s);}
FCALLSCSUB1(cc,CC,cc, STRING)
/*           ^  ^--^---------FORTRAN name will be cfcc (case insensitive).
 *           |__ C name.
 * i.e. the C routine cc is named cfcc when called from Fortran.
 */

                        PROTOCCALLSFSUB1(FC,fc, STRING)
#define FC(A1)               CCALLSFSUB1(FC,fc, STRING, A1)

main() {FC("hello"); return EXIT_SUCCESS;}
