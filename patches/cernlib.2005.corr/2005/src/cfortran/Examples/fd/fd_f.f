C /* fd_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fd.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine fd(b)
      implicit none
      character*(*) b
      character*(13) a
      data a/'birthday'/
      b = a
      call cdcfort(b)
      return
      end
