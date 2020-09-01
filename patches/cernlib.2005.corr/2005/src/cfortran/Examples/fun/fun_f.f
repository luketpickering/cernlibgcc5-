C /* fun_f.f */                  /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires fun.c         */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      integer function fadd(a,b)
      implicit none
      integer a,b
      fadd = a + b
      return
      end

      integer function funadd(fun,a,b)
      implicit none
      external fun
      integer a,b,fun
C WARNING FOR Alpha/OSF!
C The DEC Fortran and the DEC C compilers of DEC OSF/1 [RT] V1.2 (Rev. 10)
C will crash on this example as it stands.
C See cfortran.doc for a cleaner example of this misbehavior.
C Note that the routine funarg below, whose argument f is also an integer
C function, does not have this problem.
C This example will work if an extra argument is given to function 'fun'.
C i.e. For Alpha/OSF replace the following line with the kludge:
C     funadd = fun(a,b,1)
      funadd = fun(a,b)
      return
      end
