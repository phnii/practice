#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  string S; cin >> S;
  vector<pair<int,char>> W;
  for (int i = 0; i < N; i++) {
    int w; cin >> w;
    W.push_back({w, S[i]});
  }

  int adults = 0;
  for (int i = 0; i < S.length(); i++)
    if (S[i] == '1') adults++;

  sort(W.begin(), W.end());
  int correct = adults;
  int ans = correct;
  for (int i = 0; i < N; i++) {
    if (W[i].second == '0') correct++;
    else correct--;
    if (i < (N - 1)) {
      if (W[i].first != W[i + 1].first) ans = max(ans, correct);
    }
    else ans = max(ans, correct);
  }
  cout << ans << endl;

}