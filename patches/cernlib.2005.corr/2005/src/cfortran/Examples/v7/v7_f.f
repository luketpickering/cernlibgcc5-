C /* v7_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires v7.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      double precision function v7(d)
      implicit none
      external cv7
      double precision d(1,13,11,7,5,3,2), cv7
      integer i,j,k,l,m,n,o
      print *, 'function cv7 returns the value ', cv7(d)
      v7 = 0
      do             1 i=1,  2
        do           1 j=1,  3
          do         1 k=1,  5
            do       1 l=1,  7
              do     1 m=1, 11
                do   1 n=1, 13
                  do 1 o=1,  1
                    v7 = v7 + d(o,n,m,l,k,j,i) 
1     continue
      return
      end
