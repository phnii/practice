#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, Q; cin >> n >> Q;
  long long a[200200];
  long long q[200200];
  long long ans[200200];
  for (long long i = 0; i < n; i++)
    cin >> a[i];
  for (long long i = 0; i < Q; i++)
    cin >> q[i];

  for (long long i = 0; i < Q; i++) {
    long long cnt = 0;
    for (long long j = 0; j < n; j++) {
      cnt += abs(a[j] - q[i]);
    }
    ans[i] = cnt;
  }

  for (long long i = 0; i < Q; i++)
    printf("%lld\n", ans[i]);
}