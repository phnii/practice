#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);

  int cnt = 0;

  for (int i = 1; i <= n; i++) {
    if (i <= 9 || (100 <= i && i <= 999) || (10000 <= i && i <= 99999)) {
      cnt++;
    }
  }
  printf("%d", cnt);
  return 0;
}