#include<stdio.h>
#include<math.h>

double func(double x){
	return exp(x);
}

//台形則
double trap(double a, double b, int n){
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


//一重指数型
double tanh_rule(int n){
	double h;
	double s;

	/* (b - a)n */
	h = 30.0/n;
	s = 0.0;
	for(int i=-n/2;i<=n/2;i++){
		s += func(tanh(i*h))/(cosh(i*h)*cosh(i*h));
	}
	s *= h;
	return s;
}


// 二重指数型
double dexp_rule(double a,double b,int n){
	double h;
	double t;
	double s;
	double l_a,l_b;

	l_a = (b-a)*0.5;
	l_b = (b+a)*0.5;

	/* (b - a)n */
	h = 20.0/n;
	s = 0.0;
	for(int i=-n/2;i<=n/2;i++){
		t = 0.5*M_PI*sinh(i*h);
		s += func(l_a*tanh(t)+l_b)*cosh(i*h)/(cosh(t)*cosh(t));
	}
	s *= 0.5*M_PI*h*l_a;
	return s;
}

int main(void){
	double s1,s2,s3;
	double e1,e2,e3;
	double s;
	s = exp(1.0)-1.0/exp(1.0);
	printf("Err=abs(True-Approximation)\n");
	printf("e1=Trapezoidal rule, e2=Tanh Rule, e3=DoubleExponenthal Formula\n");
	for(int i=16;i<=128;i+=4){
		s1 = trap(-1.0,1.0,i);
		e1 = fabs(s - s1);
		s2 = tanh_rule(i);
		e2 = fabs(s - s2);
		s3 = dexp_rule(-1.0,1.0,i);
		e3 = fabs(s - s3);
		printf("[%5d] e1 = %.5e \t e2 = %.5e \t e3 = %.5e\n", i,e1,e2,e3);
		//printf("[%5d] e1 = %.15lf \t e2 = %.15lf \t e3 = %.15lf\n", i,e1,e2,e3);
	}
	return 0;
}
