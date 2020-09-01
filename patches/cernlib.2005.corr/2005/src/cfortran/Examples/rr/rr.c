/* rr.c == rr.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires rr_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#include "cfortran.h"


PROTOCCALLSFFUN1(FLOAT,RR,rr,INT)
#define RR(A1)               CCALLSFFUN1(RR,rr, INT, A1)
PROTOCCALLSFFUN0(STRING,FORSTR2,forstr2)
#define FORSTR2()           CCALLSFFUN0(FORSTR2,forstr2)
PROTOCCALLSFFUN1(STRING,FORSTR,forstr,STRING)
#define FORSTR(A1)          CCALLSFFUN1(FORSTR,forstr, STRING, A1)

main() {
static char aa[] = "one";
int rrr = 333;
printf("RR(rrr=%d) returns int arg. as float:%f\n",rrr,RR(rrr));
printf("FORSTR(aa=%s) returns the string arg. as:%s<-end here\n",aa,FORSTR(aa));
printf("FORSTR2() returns the string constant:%s<-end here\n",FORSTR2());
return EXIT_SUCCESS;
}
