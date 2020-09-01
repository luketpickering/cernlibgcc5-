/*
 * $Id: cstrcmp.c,v 1.4 1997/09/02 15:50:44 mclareni Exp $
 *
 * $Log: cstrcmp.c,v $
 * Revision 1.4  1997/09/02 15:50:44  mclareni
 * WINNT corrections
 *
 * Revision 1.3  1997/03/14 12:02:24  mclareni
 * WNT mods
 *
 * Revision 1.2.2.1  1997/01/21 11:34:44  mclareni
 * All mods for Winnt 96a on winnt branch
 *
 * Revision 1.2  1996/03/14 13:44:13  berezhno
 * mods for WINNT
 *
 * Revision 1.1.1.1  1996/02/26 17:16:55  mclareni
 * Comis
 *
 */
#include "comis/pilot.h"
#if !defined(CERNLIB_ALPHA_OSF)
/*CMZ :  1.16/13 16/09/93  16.09.32  by  Rene Brun*/
/*-- Author :*/

#ifdef CERNLIB_WINNT
# include <stdio.h>
#endif

#if defined(CERNLIB_QXCAPT) && defined(CERNLIB_MSSTDCALL)
/*
 int type_of_call CSTRCMP(ja,len_ja, na,jb, len_jb, nb)
    int len_ja, len_jb;
*/
 int type_of_call CSTRCMP(ja, na,jb, nb)
#else
int cstrcmp_(ja,na,jb,nb)
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
     int *na, *nb;
{

  static int i,la,lb,k; static char *a,*b;
  if ( *na >= *nb )
     {
       setaddr_lp64(*ja,*jb)
       la=*na; lb=*nb; k=1;
     }
  else
     {
       setaddr_lp64(*jb,*ja)
       la=*nb; lb=*na; k=-1;
     }
#else
     char **ja, **jb;
     int *na, *nb;
{
  int i,la,lb,k; char *a,*b;
  if ( *na >= *nb )
     {
      a=*ja; b=*jb; la=*na; lb=*nb; k=1;
      }
  else
    {
      a=*jb; b=*ja; la=*nb; lb=*na; k=-1;
     }
#endif
  for ( i=0; i<lb; i++ )
    { if(a[i] != b[i])
      { return ( (a[i] > b[i]) ? k : -k ); }
     }
  while( i < la )
    {
        if(a[i] > ' ')        return (k);
        else if( a[i] < ' ') return (-k);
        i++;
    }
    return(0);
}
#endif
