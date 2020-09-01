C /* fcb_f.f */                  /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fcb.c or .C   */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine ffcb()
      implicit none
      common /fcb/  v,w,x
      character *(13) v, w(4), x(3,2)
      print*,'FFCB:v =',v,'.'
      print*,'FFCB:w(1,2,3,4) =',w(1),',',w(2),',',w(3),',',w(4),'.'
      print*,'FFCB:x([1,2,3],1) =',x(1,1),',',x(2,1),',',x(3,1),'.'
      print*,'FFCB:x([1,2,3],2) =',x(1,2),',',x(2,2),',',x(3,2),'.'
      v      = 'fcb v'
      w(1)   = 'fcb w(1)'
      w(2)   = 'fcb w(2)'
      w(3)   = 'fcb w(3)'
      x(1,1) = 'fcb x(1,1)'
      x(2,1) = 'fcb x(2,1)'
      x(3,1) = 'fcb x(3,1)'
      x(1,2) = 'fcb x(1,2)'
      x(2,2) = 'fcb x(2,2)'
      x(3,2) = 'fcb x(3,2)'
      end
