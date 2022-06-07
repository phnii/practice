#include <bits/stdc++.h>
using namespace std;

using pint = pair<int, int>; // <人, 0 or 1>

int N;
vector<vector<pint>> v;

// 親切不親切を表すbit列を与えて、全ての正直者の全ての証言が矛盾しないときに真を返す
bool judge(int bit) {
  // N人全員について証言を確かめる
  for (int i = 0; i < N; i++) {
    // i番目の人が不親切の人なら証言は無視して次の証人に移動
    if ( !(bit & (1 << i)))
      continue;

    for (pint xy : v[i]) {
      // x番目の人はyである
      int x = xy.first;
      int y = xy.second;
      if (y == 1 && !(bit & (1 << x)))
        return false;
      
      if (y == 0 && (bit & (1 << x)))
        return false;
    }
  }
  return true;
}
 
int main() {
  cin >> N;
  v.resize(N);
  for (int i = 0; i < N; i++) {
    int A; cin >> A;
    v[i].resize(A);
    for (int j = 0; j < A; j++) {
      cin >> v[i][j].first >> v[i][j].second;
      --v[i][j].first;
    }
  }

  int res = 0;
  for (int bit = 0; bit < (1 << N); bit++) {
    if (judge(bit)) {
      // bitに含まれる正直者の数を数える
      int c = 0;
      for (int i = 0; i < N; i++) {
        if (bit & (1 << i))
          c++;
      }
      res = max(res, c);
    }
  }

  cout << res << endl;
}