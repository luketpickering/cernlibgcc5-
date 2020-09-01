#if defined(CERNLIB_QMLXIA64)

/*
 * cscal_lp64.h:
 * macro definitions for LP64 architectures (H. Vogt - Sep 2005)
 * 64-bit pointer systems require a special treatment of addresse
 * This code will be consistent with that of jumptn.c and jumpxn.c
 * in packlib/kernlib/kerngen/ccgen (usage of jumpad_)
 * It enables to stay in the 32-bit address space
 * but here the addresses have to be converted to 64 bit pointers
 *
 * special: shared objects loaded by the dynamic linker can have
 *          addresses above the 32 bit address space (*fptr)
 *          see changes in csintx.F, cskcal.F, ... 
 *          (usage of INTEGER*8 array for those pointers)
 *
 */

#if !defined (__ia64__)
/* for AMD64 and EM64T architectures */
#define setcall_lp64(type)                                                  \
 long *fptr;                                                                \
 int *n;                                                                    \
 unsigned pin[16];                                                          \
{                                                                           \
   int jumpad_();                                                           \
   type (*name)();                                                          \
   unsigned long ptr = (unsigned long)jumpad_;                              \
   ptr += *fptr;                                                            \
   name = (type (*)())ptr;                                                  \
   long p[16];                                                              \
   int  count;  for ( count=0; count<16; count++ )  p[count] = pin[count];  \
   /* end of macro */

#define setaddr_lp64(__ja, __jb)                                            \
 long aa=__ja; long bb=__jb;                                                \
 a=(char *)((long)(__ja)); b=(char *)((long)(__jb));                        \
   /* end of macro */

#else
/* for IA64 architectures */
#define setcall_lp64(type)                                                  \
 long *fptr;                                                                \
 int *n;                                                                    \
 unsigned pin[16];                                                          \
{                                                                           \
   int jumpad_();                                                           \
   type (*name)();                                                          \
   unsigned long ptr = (unsigned long)jumpad_;                              \
   ptr += *fptr;                                                            \
   name = (type (*)())ptr;                                                  \
   long p[16];                                                              \
   int  count;  for ( count=0; count<16; count++ )                          \
   {                                                                        \
/*   check for arguments containing an external                             \
 *   which have to be in the shared memory region (region 1)                \
 *   they are handled via cskcal.F in jumpcadd (entry in jumpcn.c)          \
 *   and flagged by adding the value of 0x80000000 to the address.          \
 *                                                                          \
 *   for arguments containing addresses of data they must be converted      \
 *   to be in the data segment (region 3)                                   \
 */                                                                         \
     if ((pin[count]&0x80000000) == 0)                                      \
     {                                                                      \
        p[count] = pin[count] + 0x6000000000000000;                         \
     }                                                                      \
     else                                                                   \
     {                                                                      \
        p[count] = pin[count] + 0x2000000000000000 - 0x80000000;            \
     }                                                                      \
   }                                                                        \
   /* end of macro */

#define setaddr_lp64(__ja, __jb)                                            \
 a=(char*)((long)(__ja) | 0x6000000000000000);                              \
 b=(char*)((long)(__jb) | 0x6000000000000000);                              \
   /* end of macro */

#endif
#endif

