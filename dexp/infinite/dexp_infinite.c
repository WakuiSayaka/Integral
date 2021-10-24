#include<stdio.h>
#include<math.h>

double func(double x){
	return 1.0 / (1.0 + x * x * x * x);
}

//double exponential formula [-∞,∞]
double dexp(int n){
	double h,sum = 0;
	double pi_sinh;

	h = log(3.0 * n) / n;

	for(int i = -n;i <= n; i++){
		pi_sinh = 0.5 * M_PI * sinh(i * h);
    sum += func(sinh(pi_sinh)) * cosh(i*h) * cosh(pi_sinh);
	}
  sum *= 0.5 * M_PI * h;
	return sum;
}

int main(void) {

  for(int i=1;i<=64;i*=2)  printf("[%5d]%.15lf\n",i,dexp(i));

  return 0;
}
