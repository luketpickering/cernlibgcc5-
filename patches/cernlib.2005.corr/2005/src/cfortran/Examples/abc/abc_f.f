C /* abc_f.f */                  /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires abc.c or .C   */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine abc(a,b,c)
      implicit none
      character*(*) b,a,c
      character*(13) d
      d = a
      a = b
      b = c
      c = d
      return
      end
