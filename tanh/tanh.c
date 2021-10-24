#include<stdio.h>
#include<math.h>
#include<float.h>

double func(double x){
	return 2.0 * x * x * x * x;
}

//tanh
double tanh_rule(double a,double b,int n){
	double h,sum = 0;
	double ba_sub,ba_sum;

	ba_sub = (b - a) * 0.5;
	ba_sum = (b + a) * 0.5;

	h = sqrt(6.0*M_PI/n);
	for(int i = -n;i <= n; i++){
		sum += func(ba_sub*tanh(0.5*i*h)+ba_sum)/(cosh(0.5*i*h)*cosh(0.5*i*h));
	}
	sum *= 0.5*h*ba_sub;
	return sum;
}

int main(void) {
  int a,b;

  //区間[a,b]
  a = -1;
  b = 1;

  for(int i=1;i<=65536;i*=2)  printf("[%5d]%.15lf\n",i,tanh_rule(a,b,i));

  return 0;
}
