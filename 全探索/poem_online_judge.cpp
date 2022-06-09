#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<string> str_list(n);
  vector<int> score_list(n);
  int max_score = 0;
  int ans = 0;
  set<string> st;

  for (int i = 0; i < n; i++) {
    cin >> str_list[i] >> score_list[i];
  }

  for (int i = 0; i < n; i++) {
    if (st.find(str_list[i]) != st.end())
      continue;
    if (score_list[i] > max_score) {
      max_score = score_list[i];
      ans = i + 1;
    }
    st.insert(str_list[i]);
  }

  cout << ans << endl;
}