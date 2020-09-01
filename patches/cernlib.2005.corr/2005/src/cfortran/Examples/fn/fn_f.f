C /* fn_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fn.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      double precision function fn(a,b)
      implicit none
      double precision cn,a,b
      fn = cn(a,b)
      return
      end
