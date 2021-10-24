#include<stdio.h>
#include<math.h>

double func(double x){
	return 2.0 * x * x * x * x;
}

//double exponential formula [a,b]
double dexp(double a,double b,int n){
	double h,sum = 0;
	double ba_sub,ba_sum,pi_sinh;

	ba_sub = (b - a) * 0.5;
	ba_sum = (b + a) * 0.5;

	h = log(3.0 * n) / n;
	for(int i = -n;i <= n; i++){
		pi_sinh = 0.5 * M_PI * sinh(i * h);
		sum += func(ba_sub * tanh(pi_sinh) + ba_sum) * cosh(i * h) / (cosh(pi_sinh) * cosh(pi_sinh));
	}
	sum *= 0.5 * M_PI * h * ba_sub;
	return sum;
}

int main(void) {
  int a,b;

  //区間[a,b]
  a = -1;
  b = 1;

  for(int i = 1;i <= 64;i *= 2)  printf("[%5d]%.15lf\n",i,dexp(a,b,i));

  return 0;
}
