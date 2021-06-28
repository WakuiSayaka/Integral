#include <stdio.h>
#include <math.h>

double func(double x) {
  return x*x*x;
  // return exp(x);
  // return 1.0/sqrt(x);
}

double dexp(double a,double b,int n) {
  double h;
  double s;
  double l_a,l_b;

	l_a = (b-a)*0.5;
	l_b = (b+a)*0.5;
	h = log(3.0*(double)n)/(double)n;
	s = 0.0;


	for(int i=-n;i<=n;i++){
    double t;
    t = l_a*tanh(0.5*M_PI*sinh(i*h))+l_b;
    if (b != a) {
      if (!a) {
        t = 0.5*b*exp(0.5*M_PI*sinh(i*h))/cosh(0.5*M_PI*sinh(i*h));
      } else if(!b) {
        t = 0.5*a*exp(-0.5*M_PI*sinh(i*h))/cosh(0.5*M_PI*sinh(i*h));
      }
    }
		s += func(t)*cosh(i*h)/(cosh(0.5*M_PI*sinh(i*h))*cosh(0.5*M_PI*sinh(i*h)));
	}
	s *= 0.5*M_PI*h*l_a;
	return s;
}

// f(x) = 1.0/sqrt(1.0-x)  a = 0.0 b = 1.0
double dexpf4(double a,double b,int n) {
  double h;
  double s;
  double l_a,l_b;
	l_a = (b-a)*0.5;
	l_b = (b+a)*0.5;
	h = log(3.0*(double)n)/(double)n;
	s = 0.0;

	for(int i=-n;i<=n;i++){
    s += sqrt(exp(M_PI*sinh(i*h)) + 1.0)*cosh(i*h)/(cosh(0.5*M_PI*sinh(i*h))*cosh(0.5*M_PI*sinh(i*h)));
	}
	s *= 0.5*M_PI*h*l_a;
	return s;
}




int main(void) {
  double  a,b;
  int     n=1;
  a = 0.0;  b = 2.0;
  // a = -1.0; b = 1.0;
  // a = 0.0;  b = 1.0;

  for (int i = 1; i <= 6; i++) {
    n *= 2;
    printf("[%5d] %lf \n",n,dexp(a,b,n));
    // printf("[%5d] %lf \n",n,dexpf4(a,b,n));
  }
  return 0;
}
