C /* f0_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires f0.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine fexist()
      implicit none
      print*,'FEXIST: was called'
      call exist()
      return
      end

