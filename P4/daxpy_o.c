#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 /*@-realcompare@*/
void mxsl_na_CBLAS_daxpy
 (
  int n /*! array size */,
  double da /*! double constant */,
  double *dx /*! input double array */,
  int incx /*! input stride */,
  double *dy /*! output double array */,
 int incy /*! output stride */
 )
 {
 # define FNDX(I) ((I)-1)
 # define DY(I) (dy[FNDX(I)])
 # define DX(I) (dx[FNDX(I)])
 # define MOD(I,J) ((I)%(J))
   static int i;
   static int m;
  static int ix;
   static int iy;
   static int mp1;
   if (n <= 0)
    goto bye;
   if (da == 0.)
     goto bye;
   if (incx == 1 && incy == 1)
    goto L20;
 
   ix = 1;
  iy = 1;
  if (incx < 0)
     ix = (-(n) + 1) * incx + 1;
  if (incy < 0)
     iy = (-(n) + 1) * incy + 1;
   for (i = 1; i <= n; ++i)
     {
       DY(iy) += da * DX(ix);
       ix += incx;
       iy += incy;
     }
  goto bye;

 L20:
   m = MOD(n,4);
   if (m == 0)
     goto L40;
   for (i = 1; i <= m; ++i)
     DY(i) += da * DX(i);
   if (n < 4)
     goto bye;
 L40:
   mp1 = m + 1;
   for (i = mp1; i <= n; i += 4)
     {
       DY(i) += da * DX(i);
       DY(i + 1) += da * DX(i + 1);
       DY(i + 2) += da * DX(i + 2);
       DY(i + 3) += da * DX(i + 3);
     }
 bye:
   return;
 # undef FNDX
 # undef DY
 # undef DX
 # undef MOD
 }
 
 # ifdef XTEST
 # undef SIZE
 # define SIZE 10
 int main()
 {
   const int N=SIZE;
   double X[SIZE] = {  0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
   double Y[SIZE] = { -1.0,-2.0,-3.0,-4.0,-5.0,-6.0,-7.0,-8.0,-9.0,-10.};
   const int incX = 1;
   const int incY = 1;
   const double alpha=1.5;
   int j;
   char *prog="xmxsl_na_CBLAS_daxpy";
 
   printf("\nBefore:\n");
   for (j=0; j<SIZE; j++)
   printf("%d  X[]=%g  Y[]=%g\n",j,X[j],Y[j]);
   printf("alpha=%g\n\n",alpha);
 
   printf("\n%s: Y += alpha*X\n",prog);
   mxsl_na_CBLAS_daxpy( N, alpha, X,incX, Y, incY);
 
   printf("\nAfter:\n");
   for (j=0; j<SIZE; j++)
     printf("%d  X[]=%g  Y[]=%g\n",j,X[j],Y[j]);
 
  exit(0);
 }
 /*@+realcompare@*/
# undef SIZE
# endif
#
