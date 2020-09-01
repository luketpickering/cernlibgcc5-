C /* fm_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fm.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      real function fm(r)
      implicit none
      external cm
      real cm,r
      fm = cm(r)
      return
      end
