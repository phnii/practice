#include <bits/stdc++.h>
using namespace std;

int main() {
  long max_score = -1;
  int ans = 0;
  int N; cin >> N;
  set<string> st;
  vector<string> vs(N);
  vector<long long> vi(N);

  for (int i = 0; i < N; i++) {
    string str;
    long long score;
    cin >> str >> score;
    vs[i] = str;
    vi[i] = score;
  }

  for (int i = 0; i < N; i++) {
    if (st.count(vs[i]) == 1)
      continue;
    if (vi[i] > max_score) {
      max_score = vi[i];
      ans = i + 1;
      st.insert(vs[i]);
    }
  }

  cout << ans << endl;
}