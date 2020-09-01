C /* fh_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fh.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      character*(*) function fh()
      implicit none
      character*200 cch
      fh = cch()
      return
      end
