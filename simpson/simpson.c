#include<stdio.h>
#include<math.h>

//関数f(x)
double func(double x) {
  return 2.0 * x * x * x * x;
}


//区間[a,b] 分点数n
double simpson(int a,int b,int n) {
  double h,sum = 0,mid_s = 0 ,trap_s = 0;
  //刻み幅h
  h = (b - a) / (double)n;
  //midpoint
  for (int i = 1;i <= n;i++) {
    mid_s += func(a + h * (i-0.5));
  }
  //trapezoidal
  for (int i = 1;i < n;i++) {
    trap_s += func(a + h * i);
  }
  //(trap+2mid)/3.0
  sum += 0.5 * (func(a) + func(b)) + trap_s + 2.0*mid_s;
  sum = sum/3.0;
  return h*sum;
}


int main(void) {
  int a,b;

  //区間[a,b]
  a = -1;
  b = 1;

  for(int i = 1;i <= 65536;i *= 2)  printf("[%5d]%.15lf\n",i,simpson(a,b,i));

  return 0;
}
