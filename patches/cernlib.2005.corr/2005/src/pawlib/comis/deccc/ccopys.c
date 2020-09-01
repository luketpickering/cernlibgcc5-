/*
 * $Id: ccopys.c,v 1.4 1997/09/02 15:50:38 mclareni Exp $
 *
 * $Log: ccopys.c,v $
 * Revision 1.4  1997/09/02 15:50:38  mclareni
 * WINNT corrections
 *
 * Revision 1.3  1997/03/14 12:02:22  mclareni
 * WNT mods
 *
 * Revision 1.2.2.1  1997/01/21 11:34:41  mclareni
 * All mods for Winnt 96a on winnt branch
 *
 * Revision 1.2  1996/03/14 13:44:09  berezhno
 * mods for WINNT
 *
 * Revision 1.1.1.1  1996/02/26 17:16:55  mclareni
 * Comis
 *
 */
#include "comis/pilot.h"
#if !defined(CERNLIB_ALPHA_OSF)
/*CMZ :  1.16/13 16/09/93  16.08.50  by  Rene Brun*/
/*-- Author :*/
/*-- Author :*/
 

#if defined(CERNLIB_QXCAPT) && defined(CERNLIB_MSSTDCALL)
/* void type_of_call CCOPYS(ja,len_ja, jb, len_jb, nn)
     int len_ja, len_jb;
*/
void type_of_call CCOPYS(ja, jb, nn)
#else
void ccopys_(ja,jb,nn)
#endif

/*
 * 64-bit pointer systems require a special treatment of addresses - see below -
 * using the CERNLIB_QMLXIA64 cpp flag (H. Vogt - Sep 2005)
 */

/* For Itanium, the situation is even worse.  Itanium architecture is such
 * that the data section starts at 0x6000000000000000.  The stack is
 * supposed to be between 0x80...0 and 0xa0...0 starting at the high end
 * and growing downwards, although on a test machine (merulo.debian.org)
 * it seemed instead to start at 0x6000100000000000 and grow downwards.
 * The addresses we actually get are truncated to the lowest 32 bits,
 * so we assume that those greater than 0x80000000 are in the stack.
 *
 * Constant strings are in the text section starting at 0x40...0; we hope
 * this function doesn't receive any.
 * -- Kevin McCarty
 */

#if defined(CERNLIB_QMLXIA64)
# include "cscal_lp64.h"
     int *ja, *jb;
     int *nn;
{
  int i,n; char *a,*b;
  n=*nn; 
  setaddr_lp64(*ja,*jb)

#else
     char **ja, **jb;
     int *nn;
{
  int i,n; char *a,*b;
  n=*nn; 
  a=*ja; b=*jb;
#endif
  if ( a >= b )
     for ( i=0; i<n; i++ )
          b[i]=a[i];
  else
    { if(a+n > b)
       for ( i=n-1; i>=0; i-- )
           b[i]=a[i];
      else
        for ( i=0; i<n; i++ )
           b[i]=a[i];

     }
}
#endif
