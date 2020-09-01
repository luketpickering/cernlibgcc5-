C /* f27_f.f */                  /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires f27.c         */
C /* Burkhard Burow  burow@desy.de                 1990 - 1998. */

      subroutine f27(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t
     +                ,u,v,w,x,y,z,aa)
      implicit none
      integer        a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t
     +                ,u,v,w,x,y,z,aa
      call      cf27(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t
     +                ,u,v,w,x,y,z,aa)
      return
      end
