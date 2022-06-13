#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
  long long N, W; cin >> N >> W;
  long long w[110], v[110];
  long long dp[110][110]; //dp[i][j] i番目の荷物までを詰め込んで重量がj以下である時の価値の最大値

  for (int i = 1; i <= N; i++)
    cin >> w[i] >> v[i];

  for (int i = 0; i < N; i++) {
    for (long long sum_w = 0; sum_w <= W; sum_w++) {
      if (sum_w - w[i + 1] >= 0) {
        chmax(dp[i + 1][sum_w], dp[i][sum_w - w[i + 1]] + v[i + 1]);
      }
      chmax(dp[i + 1][sum_w], dp[i][sum_w]);
    }
  }

  cout << dp[N][W] << endl;

}