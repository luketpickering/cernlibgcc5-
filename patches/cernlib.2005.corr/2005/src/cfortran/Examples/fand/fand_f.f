C /* fand_f.f */                 /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fand.c or .C  */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      logical function fand(a,b)
      implicit none
      logical cand,a,b
      fand = cand(a,b)
      return
      end
