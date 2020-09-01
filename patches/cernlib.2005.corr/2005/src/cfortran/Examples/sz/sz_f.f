C /* sz_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires sz.c          */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine sz(v, w, i)
      implicit none
      integer i,j
      character *(*) v(i), w(i)
      print*,'SZ:len(v(1 or 2 or 3 or 4))  =',len(v(1))
      print*,'SZ:len(w(1 or 2 or 3))    =',len(w(1))
      do 100 j = 1,i
        print*,'SZ:v(',j,') =',v(j),'   w(',j,') =',w(j)
100   continue
      return
      end
