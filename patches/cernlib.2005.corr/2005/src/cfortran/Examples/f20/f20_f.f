C /* f20_f.f */                  /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires f20.c         */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine f20(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t)
      implicit none
      integer        a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t
      call      cf14(a,b,c,d,e,f,g,h,i,j,k,l,m,n)
      o = 15
      p = 16
      q = 17
      r = 18
      s = 19
      t = 20
      return
      end
