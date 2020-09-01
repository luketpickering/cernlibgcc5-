C /* fi_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fi.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      character*(*) function fi(v)
      implicit none
      character*(*) v(6)
      character*200 ci
      fi = ci(v)
      return
      end
