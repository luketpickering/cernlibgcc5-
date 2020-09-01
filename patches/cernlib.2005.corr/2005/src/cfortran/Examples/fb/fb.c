/* fb.c == fb.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fb_f.f        */
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

void cb(int *i)
{printf("cb: had pointer argument to integer:%d.\n",*i); *i*=2;}
FCALLSCSUB1(cb,CB,cb, PINT)
/*           ^  ^--^---------FORTRAN name will be cfcb (case insensitive).
 *           |__ C name.
 * i.e. the C routine cb is named cfcb when called from Fortran.
 */

                        PROTOCCALLSFSUB1(FB,fb, PINT)
#define FB(A1)               CCALLSFSUB1(FB,fb, PINT, A1)

main() 
{int i,ii; i=ii=1234; 
 FB(ii); printf("MAIN: FB(i=%d) returns with i=%d.\n",i,ii);
 return EXIT_SUCCESS;
}
