#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  int cnt = 0;

  for (int i = 1; i <= n; i++) {
    int k = i;
    int d = 0;
    while (k != 0) {
      k = k / 10;
      ++d;
    }
    if (d % 2 != 0)
      cnt++;
  }
  printf("%d", cnt);
  return 0;
}