C /* sz1_f.f */                  /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires sz1.c         */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine sz1(s, is, z, iz)
      implicit none
      integer is,iz,j
      character *(*) s(is), z(iz)
      print*,'SZ1:len(s(1))  =',len(s(1)), '   len(z(1))  =',len(z(1))
      do 100 j = 1,is
        print*,'SZ1:s(',j,') =',s(j),'.'
100   continue
      do 200 j = 1,iz
        print*,'SZ1:z(',j,') =',z(j),'.'
200   continue
      return
      end
