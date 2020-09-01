C /* ft_f.f */                   /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires sz.c or .C    */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      character*(*) function ft(v, w, a)
      implicit none
      character *(*) v(4), w(4)
      real a
      print*,'FT:len(v(1 or 2 or 3 or 4))  =',len(v(1))
      print*,'FT:len(w(1 or 2 or 3))    =',len(w(1))
      print*,'FT:a = ',a
      print*,'FT:v(1,2,3,4) =',v(1),',',v(2),',',v(3),',',v(4)
      print*,'FT:w(1,2,3,4) =',w(1),',',w(2),',',w(3),',',w(4)
      ft = v(1)
      return
      end
