C /* fa_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fa.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine fa(i)
      implicit none
      integer i
      print*,'FA: integer argument =',i
      call cfortranca(i)
      return
      end
