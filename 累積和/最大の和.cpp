#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<int> v(N);
  vector<int> s(N + 1);
  for (int i = 0; i < N; i++)
    cin >> v[i];


  s[0] = 0;
  for (int i = 1; i <= N; i++) {
    s[i + 1] = s[i] + v[i];
  }

  int ans = -100000;
  for (int i = 0; i <= N - K; i++) {
    int val = s[K + i] - s[i];
    if (ans < val) ans = val;
  }

  cout << ans << endl;
}