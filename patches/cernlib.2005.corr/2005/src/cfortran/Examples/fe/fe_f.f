C /* fe_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fe.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine fe(v)
      implicit none
      character*(*) v(4)
      print*,'FE:len(v(1 or 2 or 3 or 4))  =',len(v(1))
      print*,'FE:v(1,2,3,4) =',v(1),',',v(2),',',v(3),',',v(4)
      call ce(v)
      return
      end
