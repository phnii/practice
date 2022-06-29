#include <bits/stdc++.h>
using namespace std;

int main() {
  int Q; cin >> Q;
  int n = 0;
  vector<pair<int,int>> v(Q);
  for (int i = 0; i < Q; i++) {
    int l, r; cin >> l >> r;
    if (r > n) n = r;
    v[i] = {l, r};
  }

  bitset<1000000> is_prime(0);
  for (int i = 2; i <= n; i++)
    is_prime.set(i);
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * 2; j <= n; j += i) {
        is_prime.reset(j);
      }
    }
  }

  for (int i = n; i >= 2; i--) {
    if (is_prime[i]) {
      if (!is_prime[(i + 1) / 2]) {
        is_prime.reset(i);
      }
    }
  }

  vector<int> s(n);
  s[0] = 0;
  s[1] = 0;
  s[2] = 0;
  for (int i = 3; i <= n; i++) {
    s[i + 1] = s[i] + is_prime[i];
  }

  for (int i = 0; i < Q; i++) {
    int l = v[i].first;
    int r = v[i].second;
    cout << s[++r] - s[l] << endl;
  }
}