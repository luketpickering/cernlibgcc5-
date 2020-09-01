C /* forr_f.f */                 /* anonymous ftp@zebra.desy.de */
C /* An example from cfortran.h package. Requires forr.c or .C  */
C /* Burkhard Burow  burow@desy.de                 1990 - 1996. */

      logical function forr(a,b)
      implicit none
      logical cor,a,b

      print *, 'FORTRAN thinks you called forr(a=',a,',b=',b,').'
      forr = cor(a,b)
      print *, 'FORTRAN thinks cor(a,b) returned with a=',a,',b=',b,').'

      if (a.eqv..true.)then
        print *,'Double check: a is true:',a
      endif
      if (a.eqv..false.)then
        print *,'Double check: a is false:',a
      endif
      if (.not.((a.eqv..false.) .or. (a.eqv..true.))) then
        print *,'Double check: ERROR: a is neither true nor false:',a
        print *,'  Please contact burow@desy.de'
      endif

      if (b.eqv..true.)then
        print *,'Double check: b is true:',b
      endif
      if (b.eqv..false.)then
        print *,'Double check: b is false:',b
      endif
      if (.not.((b.eqv..false.) .or. (b.eqv..true.))) then
        print *,'Double check: ERROR: b is neither true nor false:',b
        print *,'  Please contact burow@desy.de'
      endif

C      print *, ' '
C      print *, '   Testing non-FORTRAN/77 (b .eq. .true.) which'
C      print *, '    will not compile on NAG f90 or Apollo or IBM RS/6000.'
C      print *, '   Compile cfortest.c with LOGICAL_STRICT defined'
C      print *, '    if you wish this test to work as expected.'
C      print *, '   This test requires a and b to match the internal '
C      print *, '    representation of .TRUE. and .FALSE. exactly.'
C      if (a.eq..true.)then
C        print *,'Representation check: a matches .true.'
C      endif
C      if (a.eq..false.)then
C        print *,'Representation check: a matches .false.'
C      endif
C      if (.not.(a.eq..false. .or. a.eq..true.)) then
C        print *,'Representation check:  '
C        print *,'         a matches neither .true. nor .false.'
C      endif
C      if (b.eq..true.)then
C        print *,'Representation check: b matches .true.'
C      endif
C      if (b.eq..false.)then
C        print *,'Representation check: b matches .false.'
C      endif
C      if (.not.(b.eq..false. .or. b.eq..true.)) then
C        print *,'Representation check:  '
C        print *,'         b matches neither .true. nor .false.'
C      endif
C      print *,' '

      return
      end
