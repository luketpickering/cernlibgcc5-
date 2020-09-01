*
      SUBROUTINE GETARG (JARG, CHARG)
*     The following stuff is required to use gfortrans inline routine GETARG
*     It is required to avoid the calling GETARG here which conflicts
*     to the Fortran rules
      CHARACTER    CHARG*(*)
      CALL MYGETARG (JARG, CHARG)
      END

      SUBROUTINE MYGETARG (JARG, CHARG)
      CHARACTER    CHARG*(*)
*     gfortran translates the following line to a call
*     to its library routine _gfortran_getarg_i4
*     therefore it will not clash in the linking step
      CALL GETARG (JARG, CHARG)
      END

