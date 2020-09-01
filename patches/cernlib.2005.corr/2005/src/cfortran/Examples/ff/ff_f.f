C /* ff_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires ff.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine ff(v,n)
      implicit none
      integer n
      character*(*) v(4)
      print*,'FF:len(v(1 or 2 or 3 or 4))  =',len(v(1))
      print*,'FF:v(1,2,3,4) =',v(1),',',v(2),',',v(3),',',v(4)
      print*,'FF:n =',n
      call ccff(v,n)
      return
      end
