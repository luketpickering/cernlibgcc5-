C /* fstrtok_f.f */              /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Uses fstrtok.c or .C   */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      subroutine fstrtok()
      implicit none
      character*70 cstrtok, a

C Setting up NULL as the NULL pointer for cfortran.h using 4 NUL bytes.
      character NULL*4, NUL(4)
      equivalence (NULL,NUL)

C HP-UX Fortran requires DATA statements to not follow executable statements.
      DATA a/'first+second-third+forth-fifth-sixth seventh'/

CSUNBUG Have to use an equivalenced NUL array to fill NULL with 4 NUL bytes
CSUNBUG  since Sun's 'Sep 8 1987 /usr/bin/f77' has a bug which didn't set NULL
CSUNBUG  to 4 NUL bytes in the following.
CSUNBUG      NULL = CHAR(0)//CHAR(0)//CHAR(0)//CHAR(0)
      NUL(1) = CHAR(0)
      NUL(2) = CHAR(0)
      NUL(3) = CHAR(0)
      NUL(4) = CHAR(0)

C NUL character in a will force cfortran.h to pass address of a,
C not of a copy as it usually does.
      a(70:) = NULL

C String until the first '-', then until the first '+'.
      print *,cstrtok(a,    '-')
      print *,cstrtok(NULL, '+')

C Flush the rest of the string.
C Recall cfortran.h kills all trailing blanks. i.e. FORTRAN ' ' -> C "".
      print *,cstrtok(NULL, ' ')

C Further calls return nothing.
      print *,cstrtok(NULL, ' ')

      return
      end
