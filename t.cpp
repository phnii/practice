#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<pair<int, int>> v;
  for (int i = 0; i < N; i++) {
    int l, r; cin >> l >> r;
    v.push_back({l, 0});
    v.push_back({r, 1});
  }

  sort(v.begin(), v.end());

  int cnt = 0;
  for (auto [t, f] : v) {
    if (f == 0) {
      if (cnt == 0) cout << t << " ";
      cnt++;
    } else {
      cnt--;
      if (cnt == 0) cout << t << endl;
    }
  }
}