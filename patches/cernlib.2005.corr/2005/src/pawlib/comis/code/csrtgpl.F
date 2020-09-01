* Comis
*
*
#if (defined(CERNLIB_QMLXIA64))
#include "comis/pilot.h"
*CMZ :  1.18/14 10/01/95  15.41.06  by  Vladimir Berezhnoi
*-- Author : V.Berezhnoi
* special for 64 bit addresses for dynamic linking (H. Vogt)

      SUBROUTINE CSRTGPL(I)
***--------------------------
#include "comis/cspar.inc"
#include "comis/mdpool.inc"
#include "comis/cstabps.inc"
#include "comis/cstab.inc"
#include "comis/cstab64.inc"

      IPIADGV = IPIADGV + 1
      IF (IPIADGV .GT. MAXIAD64)  THEN
        WRITE (*,'(2a,I4)') 'to much addresses for dynamik linking, ',
     &                      'limit is ', MAXIAD64
        WRITE (*,'(2a)') 'increase MAXIAD64 in cstab64.inc and ',
     &                    'recompile COMIS'

        STOP
      END IF
      IADGPLV(IPIADGV) = IADGPL
      IADGP            = IPIADGV
      CALL CCOPYA(IADGP,IQ(I+2),KSIDP-2)
      END
#endif
