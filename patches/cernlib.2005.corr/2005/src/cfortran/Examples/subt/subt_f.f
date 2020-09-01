C /* subt_f.f */                 /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires subt.c        */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine subt(v, w, a)
      implicit none
      character *(*) v(4), w(4)
      real a
      print*,'SUBT:len(v(1 or 2 or 3 or 4))  =',len(v(1))
      print*,'SUBT:len(w(1 or 2 or 3))    =',len(w(1))
      print*,'SUBT:a = ',a
      print*,'SUBT:v(1,2,3,4) =',v(1),',',v(2),',',v(3),',',v(4)
      print*,'SUBT:w(1,2,3,4) =',w(1),',',w(2),',',w(3),',',w(4)
      return
      end
