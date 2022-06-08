#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<int> a(N);
  vector<int> a0(N);
  vector<vector<int>> b(K);


  for (int i = 0; i < N; i++) {
    int ai; cin >> ai;
    a[i] = ai;
    a0[i] = ai;
    b[i%K].push_back(ai);
  }


  for (int i = 0; i < K; i++) {
    sort(b[i].begin(), b[i].end());
  }

  for (int i = 0; i < N; i++) {
    a[i] = b[i % K][i / K];
  }

  sort(a0.begin(), a0.end());
  if (a == a0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}