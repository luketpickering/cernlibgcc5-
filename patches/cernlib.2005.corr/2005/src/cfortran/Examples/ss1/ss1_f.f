C /* ss1_f.f */                  /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires ss1.c or .C   */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine ss1(b)
      implicit none
      character*(*) b
      character*(13) a
      data a/'first'/
      b = a
      return
      end

      subroutine forstr1(b)
      implicit none
      character*(*) b
      character*(13) a
      character*(13) forstr
      data a/'firs'/
      b = forstr(a)
      return
      end

      character*(*) function forstr(a)
      implicit none
      character*(*) a
      forstr = a
      return
      end
