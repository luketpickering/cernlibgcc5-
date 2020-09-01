/* eq.c == eq.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires eq_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#include "cfortran.h"

/* FORTRAN_REAL, instead of float, is only required for CRAY T3E.             */

                         PROTOCCALLSFSUB0(FEQ,feq)
#define FEQ()                 CCALLSFSUB0(FEQ,feq)

#define KWBANK 690
typedef struct {
  int nzebra;
  FORTRAN_REAL gversn,zversn;
  int ixstor,ixdiv,ixcons;
  FORTRAN_REAL fendq[16];
  union {
    struct {
      int Lmain,Lr1; 
      union {FORTRAN_REAL Ws[KWBANK]; int Iws[2];}u;
    }s;
    union {
      int Lq[80];
      struct {
        int dummy[8];
        union {FORTRAN_REAL Q[2]; int Iq[2];}u;
      }s;
    }u;
  }u;
} GCBANK_DEF;
#define lmain u.s.Lmain
#define lr1   u.s.Lr1
#define ws    u.s.u.Ws
#define iws   u.s.u.Iws
#define lq    u.u.Lq
#define q     u.u.s.u.Q
#define iq    u.u.s.u.Iq
#define GCbank COMMON_BLOCK(GCBANK,gcbank)
COMMON_BLOCK_DEF(GCBANK_DEF,GCbank);
GCBANK_DEF GCbank;

main() {
FEQ();
printf("GCbank.nzebra       = %d.\n", GCbank.nzebra);
printf("GCbank.gversn       = %f.\n", GCbank.gversn);
printf("GCbank.zversn       = %f.\n", GCbank.zversn);
printf("GCbank.ixstor       = %d.\n", GCbank.ixstor);
printf("GCbank.ixcons       = %d.\n", GCbank.ixcons);
printf("GCbank.fendq[15]    = %f.\n", GCbank.fendq[15]);
printf("GCbank.lmain        = %d.\n", GCbank.lmain);
printf("GCbank.lr1          = %d.\n", GCbank.lr1);
printf("GCbank.ws[KWBANK-1] = %f.\n", GCbank.ws[KWBANK-1]);
printf("GCbank.iq[0]        = %d.\n", GCbank.iq[0]);
return EXIT_SUCCESS;
}
