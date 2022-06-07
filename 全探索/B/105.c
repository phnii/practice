#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);

  int ans = 0;

  for (int i = 1; i <= n; i += 2) {
    int cnt  = 0;
    for (int j = 1; j <= i; j++) {
      if (i % j == 0)
        cnt++;
    }
    if (cnt == 8)
      ans++;
  }
  printf("%d", ans);
  return 0;
}