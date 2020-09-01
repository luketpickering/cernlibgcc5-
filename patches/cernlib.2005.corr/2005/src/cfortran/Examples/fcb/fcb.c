/* fcb.c == fcb.C */           /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fcb_f.f       */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#include "cfortran.h"


                          PROTOCCALLSFSUB0(FFCB,ffcb)
#define FFCB()                 CCALLSFSUB0(FFCB,ffcb)

typedef struct { char v[13],w[4][13],x[2][3][13]; } FCB_DEF;
#define Fcb COMMON_BLOCK(FCB,fcb)
COMMON_BLOCK_DEF(FCB_DEF,Fcb);
FCB_DEF Fcb;

main() {
char cv[14];
static char cw[4][14]    = { "C's w[0]", "C's w[1]", "C's w[2]", "C's w[3]"};
static char cx[2][3][14] = {{"C's x[0][0]", "C's x[0][1]", "C's x[0][2]"}, 
                            {"C's x[1][0]", "C's x[1][1]", "C's x[1][2]"}};
C2FCBSTR("C's V" ,Fcb.v,0);
C2FCBSTR(cw      ,Fcb.w,1);
C2FCBSTR(cx      ,Fcb.x,2);
FFCB();
FCB2CSTR(Fcb.v   ,cv   ,0);
FCB2CSTR(Fcb.w   ,cw   ,1);
FCB2CSTR(Fcb.x   ,cx   ,2);
printf("FFCB returns v = %s.\n",cv);
printf("FFCB returns w[1,2,3,4] = %s,%s,%s,%s.\n",cw[0],cw[1],cw[2],cw[3]);
printf("FFCB returns x[0,(1,2,3)] = %s,%s,%s.\n",cx[0][0],cx[0][1],cx[0][2]);
printf("FFCB returns x[1,(1,2,3)] = %s,%s,%s.\n",cx[1][0],cx[1][1],cx[1][2]);
return EXIT_SUCCESS;
}
