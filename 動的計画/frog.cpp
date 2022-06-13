#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
  int n; cin >> n;

  int h[n + 1];
  int dp[n + 1];
  for (int i = 0; i < n+1; i++) {

  }

  for (int i = 1; i <= n; i++)
    cin >> h[i];

  memset(dp, INF, sizeof(dp));

  dp[0] = 0;
  dp[1] = 0;
  dp[2] = abs(h[1] - h[2]);
  for (int i = 3; i <= n; i++) {
    int r1 = dp[i - 1] + abs(h[i] - h[i - 1]);
    int r2 = dp[i - 2] + abs(h[i] - h[i - 2]);
    dp[i] = min(r1, r2);
  }

  cout << dp[n] << endl;

}