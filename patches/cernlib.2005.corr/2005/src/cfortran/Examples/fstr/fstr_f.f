C /* fstr_f.f */                 /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fstr.c        */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine fstr()
      implicit none
      character*(4) a,b,c
      character*(1) d(5)
      character*(5) dd
      equivalence (d,dd)
      character*(16) n

      call pstru(n)
      print *,n,'<-'

      a      = '1'
      a(2:2) = CHAR(0)
      call ppstr(a)

      b      = '22'
      call pstr(b)
      print *,b,'<-'
      call pstr(b)
      print *,b,'<-'

      c(1:1) = CHAR(0)
      c(2:2) = CHAR(0)
      c(3:3) = CHAR(0)
      c(4:4) = CHAR(0)
      call pnstr(c)
      c      = '333'
      c(4:4) = CHAR(0)
      call pnstr(c)

      call pnstr(b)
      print *,b,'<-'
      call pnstr(b)
      print *,b,'<-'

      c(1:1) = CHAR(0)
      c(2:2) = CHAR(0)
      c(3:3) = CHAR(0)
      c(4:4) = CHAR(0)
      call pnstr(c)
      d(1)   = '1'
      d(2)   = '2'
      d(3)   = '3'
      d(4)   = '4'
      d(5)   = CHAR(0)
C Need to use equivalenced dd because using d causes f90 to complain:
C Error: Inconsistent structure for arg 1 in call to PPSTR at line 533
      call ppstr(dd)
      call pstr(b)
      print *,b,'<-'
      call pstr(b)
      print *,b,'<-'

      return
      end
