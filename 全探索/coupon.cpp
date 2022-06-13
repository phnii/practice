#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k, x; cin >> n >> k >> x;
  vector<long long> a(n);
  vector<int> b(n);
  long long sum = (long long)0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  long long cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += a[i] / x;
  cnt = min(cnt, k);
  sum -= cnt * x;
  k -= cnt;

  for (int i = 0; i < n; i++)
    a[i] %= x;
  sort(a.begin(), a.end());

  for (int i = 0; i < n; i++) {
    if (k == 0 ) break;
    sum -= a[n - 1 - i];
    k--;
  }

  cout << sum << endl;
}