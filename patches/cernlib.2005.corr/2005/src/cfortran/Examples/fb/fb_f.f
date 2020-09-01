C /* fb_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fb.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine fb(i)
      implicit none
      integer i
      print*,'FB: integer argument =',i
      i = i*2
      call cfcb(i)
      return
      end
