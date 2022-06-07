#include <bits/stdc++.h>
#include <string>
using namespace std;
 
int main() {
  int n; //スイッチ個数
  int m; //電球個数
  cin >> n >> m;

  int light_switches[m][n];
  int k_lis[m]; //各電球に何個のスイッチが繋がっているか

  for (int i = 0; i < m; i++) {
    int ki;
    cin >> ki;
    k_lis[i] = ki;
    for (int j = 0; j < ki; j++) {
      int a; cin >> a;
      light_switches[i][j] = --a;
    }
  }

  int p[m];
  for (int i = 0; i < m; i++) {
    cin >> p[i];
  }

  int cnt = 0;
  // 全てのスイッチのon/offパターンを渡る
  for (int bit = 0; bit < (1 << n); bit++) {
    // 全ての電球を渡る
    int on = 0;
    for (int j = 0; j < m; j++) {

      // 電球jと繋がっているスイッチでonの個数を求める
      int swch_on = 0;
      int swch_num = k_lis[j];
      for (int l = 0; l < swch_num; l++) {
        if ((bit & (1 << light_switches[j][l])))
          swch_on++;
      }

      if (swch_on % 2 == p[j])
        on++;

    }
    if (on == m) {
      cnt++;
    }
  }
  cout << cnt << endl;
}