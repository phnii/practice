#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, w; cin >> n >> w;
  vector<int> a(n + 2);
  set<int> st;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  a[n] = 0; a[n + 1] = 0;
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n + 1; j++) {
      for (int k = j + 1; k < n + 2; k++) {
        int sum = a[i] + a[j] + a[k];
        if (sum <= w && st.count(sum) == 0) {
          cnt++;
          st.insert(sum);
        }
      }
    }
  }
  cout << cnt << endl;
}