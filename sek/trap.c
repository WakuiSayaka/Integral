#include <stdio.h>
#include <math.h>

double func(double x) {
  return x*x*x;
  // return 2.0*x*x*x*x;
  // return exp(x);
}

double trap(double a,double b,int n) {
  double h;
  double s;
  h = (b-a)/n;
  s = 0.5*(func(a)+func(b));
  for(int i=1;i<n;i++){
    s += func(a+i*h);
  }
  s *= h;
  return s;
}


int main(void) {
  double  a,b;
  int     n=1;
  a = 0.0;  b = 2.0;
  // a = -1.0; b = 1.0;

  for (int i = 1; i <= 6; i++) {
    n *= 2;
    printf("[%5d] %lf \n",n,trap(a,b,n));
  }
  return 0;
}
