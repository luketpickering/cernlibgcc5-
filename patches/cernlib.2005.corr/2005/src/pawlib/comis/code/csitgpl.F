* Comis
*
*
#if (defined(CERNLIB_QMLXIA64))
#include "comis/pilot.h"
*CMZU:  1.16/16 04/10/93  12.14.52  by  Vladimir Berezhnoi
*-- Author : V.Berezhnoi
* special for 64 bit addresses for dynamic linking (H. Vogt)
      INTEGER FUNCTION CSITGPL(IP)
***------------------------------
*   it is last routine from the tables-set.
***-----------------------------
#include "comis/cspar.inc"
#include "comis/mdpool.inc"
#include "comis/cspnts.inc"
#include "comis/cstabps.inc"
#include "comis/cstab64.inc"
      I=MHLOC(KSIDP+NWIDEN)
      IQ(I)=0
      IQ(I+1)=NCIDEN
      DO 1 K=1,NWIDEN
        IQ(I+KSIDP-1+K)=IDEN(K)
   1  CONTINUE
      CALL CSRTGPL(I)
      IF(IP.EQ.0)THEN
        IPGP=I
      ELSE
        IQ(IP)=I
      ENDIF
      CSITGPL=I
      END
#endif
