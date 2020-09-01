/* q.c == q.C */               /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires q_f.f         */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

#undef  ROUTINE_4
#if defined(__cplusplus)
#define ROUTINE_4 (int (*)(const void *,const void *))
#else
#define ROUTINE_4 (int (*)())
#endif
FCALLSCSUB4(qsort,FQSORT,fqsort, PVOID, INT, INT, ROUTINE)
/* Note that we've assumed in the above that size_t == int */


                        PROTOCCALLSFSUB1(FQSORTEX,fqsortex, INT)
#define FQSORTEX(SIZEOF_INT) CCALLSFSUB1(FQSORTEX,fqsortex, INT, SIZEOF_INT)

main() {
#ifdef PowerStationFortran
printf("\n\
        Apologies. As described in cfortran.doc, MSPS Fortran provides no\n\
        easy way to pass a Fortran routine as an argument to a C routine,\n\
        so this qsort() example crashes for MSPS Fortran.\n\
        \n\
        As a kludge, the example works on MSPS Fortran by either\n\
        - using MSPS Fortran language extensions\n\
        or\n\
        - by removing the 'integer function cmp(a,b)' routine from cfortex.f\n\
          and instead using the following C routine.\n\
            int CMP( int *a, int *b) { return *a-*b ; }\n\
        \n\
        It remains a mystery why the SUB_SELECT example works\n\
        for MSPS Fortran, since it should crash due to the same problem.\n\
        Presumably the faulty stack clearing is not fatal for SUB_SELECT.\n\
        \n");
#else
FQSORTEX(sizeof(int));
#endif
return EXIT_SUCCESS;
}
