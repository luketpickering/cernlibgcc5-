C /* vv_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires vv.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine vv(d,f,i)
      implicit none
      double precision d(2,2)
      real             f(2,2)
      integer          i(2,2)
      call cvv(d,f,i)
      return
      end
