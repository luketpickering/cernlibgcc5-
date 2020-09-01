C /* fg_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fg.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      integer function fg()
      implicit none
      integer ccg
      fg = ccg()
      return
      end
