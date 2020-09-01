/* fstr.c == fstr.C */         /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fstr_f.f      */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

void Pstru(char *s) { strcpy(s,"new pstring"); return;}
FCALLSCSUB1(Pstru,PSTRU,pstru, PSTRING)

void Pstr(char *s)
{
static char *save=NULL;
char *temp;
int ls, lsave;
/* If required, reset, or prepare to reset the saved location. */
if (!s || !save) { save=s; return; }
ls    = strlen(s   );
lsave = strlen(save);
temp = (char *)malloc(ls>lsave?ls:lsave);
/* Switch contents of argument with contents of saved string. */
strcpy(temp,save);
strcpy(save,s   );
strcpy(s   ,temp);
free(temp);
return;
}
/* Provide 3 interfaces using the the 3 types of PSTRING. */
FCALLSCSUB1(Pstr,PSTR,pstr,   PSTRING)
FCALLSCSUB1(Pstr,PNSTR,pnstr, PNSTRING)
FCALLSCSUB1(Pstr,PPSTR,ppstr, PPSTRING)


                          PROTOCCALLSFSUB0(FSTR,fstr)
#define FSTR()                 CCALLSFSUB0(FSTR,fstr)

main() { FSTR(); return EXIT_SUCCESS;}
