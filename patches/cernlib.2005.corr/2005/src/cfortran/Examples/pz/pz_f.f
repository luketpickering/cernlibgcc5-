C /* pz_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires pz.c          */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine pz(s, is, z, iz)
      implicit none
      integer is,iz,j
      character *(*) s(is),z(iz)
      print*,'PZ:len(s(1))  =',len(s(1)), '   len(z(1))  =',len(z(1))
      do 100 j = 1,is
        print*,'PZ:s(',j,') =',s(j),'.'
        s(j) = '12345678'
100   continue
      do 200 j = 1,iz
        print*,'PZ:z(',j,') =',z(j),'.'
        z(j) = '12345678'
200   continue
      return
      end
