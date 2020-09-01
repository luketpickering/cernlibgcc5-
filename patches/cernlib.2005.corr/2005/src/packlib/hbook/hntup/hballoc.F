*
* $Id: hballoc.F,v 1.1.1.1 1996/01/16 17:07:56 mclareni Exp $
*
* $Log: hballoc.F,v $
* Revision 1.1.1.1  1996/01/16 17:07:56  mclareni
* First import
*
*
#include "hbook/pilot.h"
*CMZ :  4.22/09 22/07/94  12.48.52  by  Fons Rademakers
*-- Author :    Fons Rademakers   05/10/92
      SUBROUTINE HBALLOC(IDN,CHDIR,VAR,BLOCK,ITYPE,ISIZE,IFIRST,NELEM,
     +                   IBASE,IOFF,NUSE)
*.==========>
*.
*.   Dynamically allocate ISIZE*NELEM bytes for the storage of column
*.   VAR1 in BLOCK1 in Ntuple IDN. The allocated space can be accessed
*.   using IOFF, which is the offset from the base address IBASE.
*.   The first element of allocated space is IBASE(IOFF+1). If IOFF=0
*.   then there was not enough memory to allocate the space. When
*.   NUSE=1 then the buffer has been allocated for the first time and
*.   needs to be filled. If NUSE>1 then the buffer has already been
*.   used before and does not need to be filled again.
*.
*..=========> ( A.A.Rademakers )
*
      CHARACTER*(*)  CHDIR, VAR, BLOCK
      INTEGER        IDN, ITYPE, ISIZE, NELEM, NUSE, IFIRST, IBASE(1)
#if defined(CERNLIB_QMLXIA64)
      INTEGER*8      IBUF(1), IOFF
      PARAMETER      (NADUPW=4, LADUPW=2)
#else
      INTEGER        IBUF(1), IOFF
#endif
*
      LC = LENOCC(CHDIR)
      LV = LENOCC(VAR)
      LB = LENOCC(BLOCK)
*
      CALL HBALLO1(IDN, CHDIR, LC, VAR, LV, BLOCK, LB, ITYPE, ISIZE,
     +             IFIRST, NELEM, IBUF, NUSE)
*
      IF (NUSE .EQ. 0) THEN
         IOFF = 0
      ELSE
#if defined(CERNLIB_QMLXIA64) && defined(CERNLIB_QMGLIBC)
*        IBUF contains an address (dynamic memory allocation) 
*        which may exceed the 32 bit address space
*        use intrinsic LOC function here (which returns a 64 bit address)
*        IOFF is used afterwards as index to the PAWC common
         IOFF = IBUF(1) - LOC(IBASE(1))/NADUPW
#else
         IOFF = IBUF(1) - LOCF(IBASE(1))
#endif
      ENDIF
*
      END
