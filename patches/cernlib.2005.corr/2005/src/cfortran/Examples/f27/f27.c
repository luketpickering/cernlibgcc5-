/* f27.c == f27.C */           /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires f27_f.f       */
/* Burkhard Burow  burow@desy.de                 1990 - 1998. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

void Cf27(int *a, int *b, int *c, int *d, int *e, int *f, int *g, int *h, int *i, int *j, int *k, int *l, int *m,
          int *n, int *o, int *p, int *q, int *r, int *s, int *t, int *u, int *v, int *w, int *x, int *y, int *z,
          int *aa)
  {  *a =  1; *b =  2; *c =  3; *d =  4; *e =  5; *f =  6; *g =  7;
     *h =  8; *i =  9; *j = 10; *k = 11; *l = 12; *m = 13; *n = 14;
     *o = 15; *p = 16; *q = 17; *r = 18; *s = 19; *t = 20; *u = 21;
     *v = 22; *w = 23; *x = 24; *y = 25; *z = 26; *aa= 27;
     return;}
FCALLSCSUB27(Cf27,CF27,cf27, PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT, \
                                  PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT,PINT)

#if MAX_PREPRO_ARGS>31 && !defined(CFSUBASFUN)
   PROTOCCALLSFSUB27(F27,f27, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT)
#define F27(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,AA) \
        CCALLSFSUB27(F27,f27, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, PINT, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, AA)

main()  {
int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, j=0, k=0, l=0, m=0, n=0,
    o=0, p=0, q=0, r=0, s=0, t=0, u=0, v=0, w=0, x=0, y=0, z=0, aa=0;
F27(   a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa);
printf(" F27: %3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d.\n",
       a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa);
return EXIT_SUCCESS;
}
#else
main()  {
printf("Sorry 14 argument max. via cfortran.h for this C preprocessor or for CFSUBASFUN.\n");
return EXIT_SUCCESS;
}
#endif
