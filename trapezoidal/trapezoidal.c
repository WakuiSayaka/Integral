#include<stdio.h>
#include<math.h>

//関数f(x)
double func(double x) {
  return 2.0 * x * x * x * x;
}


//区間[a,b] 分点数n
double trapezoidal(int a,int b,int n) {
  double h,sum = 0;
  //刻み幅h
  h = (b - a) / (double)n;
  for (int i = 1;i < n;i++) {
    sum += func(a + h * i);
  }
  sum += 0.5 * (func(a) + func(b));
  return h*sum;
}


int main(void) {
  int a,b;

  //区間[a,b]
  a = -1;
  b = 1;

  for(int i = 1;i <= 65536;i *= 2)  printf("[%5d]%.15lf\n",i,trapezoidal(a,b,i));


  return 0;
}
