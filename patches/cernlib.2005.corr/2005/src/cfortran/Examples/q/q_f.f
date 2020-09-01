C /* q_f.f */                    /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires q.c           */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine fqsortex(size)
      implicit none
C Because it's convinient here, we let C tell us the size of INTEGER.
      integer size

      integer base(10),cmp,i
      external cmp
      data base /1,10,2,9,3,8,4,7,5,6/
      call fqsort(base,10,size,cmp)
      print '(10I3)', (base(i), i=1,10)
      return
      end

      integer function cmp(a,b)
      implicit none
      integer a,b
      cmp = a-b
      return
      end
