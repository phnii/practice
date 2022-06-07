#include <stdio.h>

int min(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}

int main(void) {
  int a, b, k;
  scanf("%d %d %d", &a, &b, &k);

  int divisors[100];
  int ptr = 0;

  for (int i = min(a, b); i >= 1; i--) {
    if (a % i == 0 && b % i == 0)
      divisors[ptr++] = i;
  }

  printf("%d", divisors[k - 1]);
  return 0;
}