#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  vector<string> v(n);
  int ans = 0;

  for (int i = 0; i < n; i++)
    cin >> v[i];

  // 選んだ文字列の組み合わせについて全パターンを調べる
  for (int bit = 0; bit < (1 << n); bit++) {
    vector<int> counter(26); // 選ばれたパターンの中でa ~ z (0 ~ 26)が何回含まれているかカウントする
    for (int i = 0; i < n; i++) {
      // i番目の文字列は選ばれている
      if (bit & (1 << i)) {
        for (int j = 0; j < v[i].length(); j++) {
          int idx = v[i][j] - 'a';
          counter[idx]++;
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
      if (counter[i] == k)
        cnt++;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}