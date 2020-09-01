C /* eq_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires eq.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine feq()
      parameter (kwbank=690)  
C The & in the next line is for f90 line continuation.
C It is in column 74, i.e. part of f77 comments.
      common/gcbank/nzebra,gversn,zversn,ixstor,ixdiv,ixcons,fendq(16)   &
     &             ,lmain,lr1,ws(kwbank)    
      dimension iq(2),q(2),lq(80),iws(2)  
      equivalence (q(1),iq(1),lq(9)),(lq(1),lmain) ,(iws(1),ws(1))
      nzebra     = 1
      gversn     = 2
      zversn     = 3
      ixstor     = 4
      ixcons     = 5
      fendq(16)  = 6
      lmain      = 7
      lr1        = 8
      ws(kwbank) = 9
      lq(9)      = 10
      end
