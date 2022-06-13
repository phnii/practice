#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
  int N; cin >> N;
  int p[102];
  for (int i = 1; i <= N; i++)
    cin >> p[i];
  
  int max = 0;
  for (int i = 1; i <= N; i++)
    max += p[i];
  
  bool dp[N + 1][max + 2]; // dp[i][j] i番目までの合計でj点をとるパターンがあるか

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= max; j++) {
      dp[i][j] = false;
    }
  }

  dp[1][p[1]] = true;
  dp[1][0] = true;

  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= max; j++) {
      dp[i + 1][j] = dp[i][j - p[i + 1]] || dp[i][j];
    }
  }

  int cnt = 0;
  for (int i = 0; i <= max; i++) {
    if (dp[N][i])
      cnt++;
  }

  cout << cnt << endl;
}