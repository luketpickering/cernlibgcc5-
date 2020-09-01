C /* sub_f.f */                  /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires sub.c         */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine funarg(f,a,b,c)
      implicit none
      external fadd3,f
      integer a,b,c,f
      c = f(fadd3,a,b)
      return
      end

      subroutine fadd3(a,b,c)
      implicit none
      integer a,b,c
      c = a + b
      return
      end
