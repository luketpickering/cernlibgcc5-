C /* fz_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fz.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      character*(*) function fz(v, w, i)
      implicit none
      integer i,j
      character *(*) v(i), w(i)
      print*,'FZ:len(v(1 or 2 or 3 or 4))  =',len(v(1))
      print*,'FZ:len(w(1 or 2 or 3))    =',len(w(1))
      do 100 j = 1,i
        print*,'FZ:v(',j,') =',v(j),'   w(',j,') =',w(j)
100   continue
      fz = v(1)
      return
      end
