#include <stdio.h>

long long f(long long a, long long b) {
  long long num = 0;
  if (a < b)
    a = b;
  while (a >= 1) {
    num++;
    a /= 10;
  }
  return num;
}

int main(void) {
  long long n;
  scanf("%lld", &n);

  long long min = 1000000000;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      long long b = n / i;
      min = f(i, b) < min ? f(i, b) : min;
    }
  }
  printf("%lld", min);
  return 1;
}