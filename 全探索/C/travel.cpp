#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0;
  int N, K; cin >> N >> K;
  vector<vector<int>> v(N);
  for (int i = 0; i < N; i++) {
    v[i].resize(N+1);
    for (int j = 0; j < N; j++) {
      cin >> v[i][j];
    }
  }

  vector<int> r(N + 1);
  for (int i = 0; i < N; i++) {
    r[i] = i;
  }
  r[N] = 0;


  do {
    int sum = 0;
    // r上のiから出発してi+1までいく時間を合計していく
    for (int i = 0; i < N; i++) {
      sum += v[r[i]][r[i + 1]];
    }
    if (sum == K)
      ans++;
  } while (next_permutation(r.begin() + 1, r.end() - 1));

  cout << ans << endl;
}