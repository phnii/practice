#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<long long> A(N), B(N), C(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  for (int i = 0; i < N; i++)
    cin >> B[i];
  for (int i = 0; i < N; i++)
    cin >> C[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  long long ans = 0;

  for (int i = 0; i < N; i++) {
    long long a = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
    long long c =  upper_bound(C.begin(), C.end(), B[i]) - C.begin();
    ans += a * (N - c);
  }
  cout << ans << endl;
}