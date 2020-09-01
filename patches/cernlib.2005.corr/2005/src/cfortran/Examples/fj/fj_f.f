C /* fj_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fj.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      character*(*) function fj(v)
      implicit none
      integer v
      character*200 cj
      print*,'FJ:v =',v
      fj = cj(v)
      return
      end
