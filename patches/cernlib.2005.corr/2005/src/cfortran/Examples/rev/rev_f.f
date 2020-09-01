C /* rev_f.f */                  /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires rev.c or .C   */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine rev(a)
      implicit none
      integer a(2),t
      t    = a(1)
      a(1) = a(2)
      a(2) = t
      return
      end

      integer function frev(a)
      implicit none
      integer a(2)
      frev = a(1)
      a(1) = a(2)
      a(2) = frev
      return
      end
