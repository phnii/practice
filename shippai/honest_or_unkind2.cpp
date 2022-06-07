#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int ans = 0;
  int n; cin >> n;
  vector<int> s(n); 
  vector<vector<vector<int>>> A;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    s[i] = a;
    for (int j = 0; j < a; j++) {
      int x, y; cin >> x >> y;
      A[i][j][0] = x;
      A[i][j][1] = y;
    }
  }

  int cnt = 0;
  // n人の親切不親切をbit列で表現し全パターンをなぞる
  for (int bit = 0; bit < (1 << n); bit++) {
    int shoujiki = 0;
    int c = 0;  // 正直者の証言の数
    int c0 = 0; // 正直者の証言で証言が矛盾しなかった数

    // i 番目の人の証言の矛盾を確かめる(i番目の人が親切のbitパターンの時のみ)
    for (int i = 0; i < n; i++) {
      if ((bit & (1 << i)) == 1) {
      // i番目の人のj番目の証言について矛盾を確かめる
        shoujiki++;
        for (int j = 0; j < s[i]; j++) {
          int x = A[i][j][0];
          int y = A[i][j][1];
          c++;
          if ((bit & (1 << x)) == y)
            c0++;
        }
      }
    if (c == c0) {
      ans = (shoujiki > ans)? shoujiki : ans;
    }
    }
  }
  cout << ans << endl;
}