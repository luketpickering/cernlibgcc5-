C /* fc_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fc.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine fc(b)
      implicit none
      character*(*) b
      print*,'FC: string argument =',b
      call cfcc(b)
      return
      end
