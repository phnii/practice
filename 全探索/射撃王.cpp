#include <bits/stdc++.h>
using namespace std;

long long N;
vector<long long> H;
vector<long long> S;

bool f(long long X) {
  vector<long long> T(N);
  for (long long i = 0; i < N; i++) {
    if (X - H[i] < 0) return false;

    T[i] = (X - H[i]) / S[i];
  }

  sort(T.begin(), T.end());
  for (long long i = 0; i < N; i++) {
    if (T[i] < i) return false;
  }
  return true;
}

int main() {
  cin >> N;
  H.resize(N);
  S.resize(N);
  for (long long i = 0 ; i < N; i++)
    cin >> H[i] >> S[i];

  // 二分探索
  long long l = 0;
  long long r = 1ll << 60;
  long long c;
  while (l <= r) {
    c = (l + r) / 2;
    if (f(c)) {
      r = c - 1;
    } else {
      l = c + 1;
    }
  }
  cout << l << endl;
}