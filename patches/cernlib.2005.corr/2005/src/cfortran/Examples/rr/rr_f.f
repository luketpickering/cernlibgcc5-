C /* rr_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires rr.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      character*(*) function forstr(a)
      implicit none
      character*(*) a
      forstr = a
      return
      end

      real function rr(i)
      implicit none
      integer i
      rr = i
      return
      end

      character*(*) function forstr2()
      implicit none
C      character*(13) a   VAX/Ultrix complains about these ().
      character*13 a
      data a/'first'/
      forstr2 = a
      return
      end
