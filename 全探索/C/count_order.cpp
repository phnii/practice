#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> P(N);
  vector<int> Q(N);
  vector<int> A(N);

  for (int i = 0; i < N; i++)
    cin >> P[i];
  for (int i = 0; i < N; i++)
    cin >> Q[i];

  for (int i = 0; i < N; i++)
    A[i] = i + 1;

  int a = 1; int b = 1; int s = 1;

  do {
    if (A == P) a = s;
    if (A == Q) b = s;
    s++;
  } while (next_permutation(A.begin(), A.end()));

  int ans = abs(a - b);

  cout << ans;
  
}