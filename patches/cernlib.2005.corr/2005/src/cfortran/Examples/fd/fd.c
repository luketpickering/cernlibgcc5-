/* fd.c == fd.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fd_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

/* The next 2 lines tell cfortran.h that for the subsequent FCALLSCSUBn
 *  and FCALLSCSUBn declarations, FORTRAN entry points to C routines have the 
 *  C name prefaced with the characters 'CFORT'.
 */
#undef  fcallsc
#define fcallsc(UN,LN) append_fcallsc(CFORT,cfort,UN,LN)


void cd(char *s)
{printf("cd: had string argument:%s.\n",s); strcpy(s,"to you 12345678");}
FCALLSCSUB1(cd,CD,cd, PSTRING)
/*           ^  ^--^---------FORTRAN name will be cdcfort (case insensitive).
 *           |__ C name.
 * i.e. the C routine cd is named cdcfort when called from Fortran.
 */

                        PROTOCCALLSFSUB1(FD,fd, PSTRING)
#define FD(A1)               CCALLSFSUB1(FD,fd, PSTRING, A1)

main() 
{static char i[] = "happy     "; static char ii[] = "happy      "; 
 FD(ii); printf("MAIN: FD(i=%s) returns with i=%s.\n",i,ii);
 return EXIT_SUCCESS;
}
