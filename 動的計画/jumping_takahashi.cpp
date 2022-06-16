#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X; cin >> N >> X;
  vector<vector<bool>> dp(N + 1, vector<bool>(X + 1, false)); //dp[i][j] i回ジャンプしてjにいることができるか
  vector<bool> v(X + 1);
  dp[0][0] = true;
  for (int i = 1; i <= N; i++) {
    int a, b; cin >> a >> b;
    for (int j = 0; j <= X; j++) {
      if (j - a >= 0 && dp[i - 1][j - a])
        dp[i][j] = true;
      if (j - b >= 0 && dp[i - 1][j - b])
        dp[i][j] = true;
    }
  }

  if (dp[N][X]) cout << "Yes" << endl;
  else cout << "No" << endl;
}