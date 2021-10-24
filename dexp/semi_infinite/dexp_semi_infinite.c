#include<stdio.h>
#include<math.h>

double func(double x){
	return 1.0 / (1.0 + x * x);
  // return exp(-x)*sin(x);
}

//double exponential formula [a,∞] , [-∞,b]
double dexp(double a,int n){
	double h,sum = 0;
	double pi_sinh;

	h = log(3.0 * n) / n;

	for(int i = -n;i <= n; i++){
		pi_sinh = 0.5 * M_PI * sinh(i * h);
    sum += func(a + exp(pi_sinh)) * cosh(i*h) * exp(pi_sinh) * 0.5 * M_PI;
    // 被積分関数がexp(-kx)g(x)のように指数的に減衰する場合は以下を使用。
    // sum += func(a + exp(i * h - exp(-i * h))) *( 1.0 + exp(-i * h) )* exp(i * h - exp(-i * h));
	}
  sum *= h;
	return sum;
}

int main(void) {
  int a;

  //区間[a,∞]
  a = 0;

  for(int i=1;i<=64;i*=2)  printf("[%5d]%.15lf\n",i,dexp(a,i));

  return 0;
}
