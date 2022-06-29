#include <bits/stdc++.h>
using namespace std;

/* 全ての海マスについて全探索する
   初めに全探索の対象の海マスの一つに対してdfsをする
   dfsは以後指定したマスに隣接する陸マスに再帰的に波及して
   一つ波及するごとにcntの値が一つ増える
   最後に初めに指定した海マスから波及した島の総面積が求まるので、入力時の陸の総面積と比較する
*/

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<string> field(10);
bool seen[10][10];
int cnt = 0;

void dfs(int h, int w) {
  seen[h][w] = true;
  for (int dir = 0; dir < 4; dir++) {
    int nh = h + dx[dir];
    int nw = w + dy[dir];

    if (nh < 0 || nh >= 10 || nw < 0 || nw >= 10) continue;
    if (field[nh][nw] == 'x') continue;
    if (seen[nh][nw]) continue;
    cnt++;
    dfs(nh, nw);
  }
}

int main() {
  int S = 0; // 陸地面積
  bool ans = false;
  for (int i = 0; i < 10; i++) {
    string s; cin >> s;
    field[i] = s;
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == 'o') S++;
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (field[i][j] == 'o') continue;

      memset(seen, 0, sizeof(seen));
      cnt = 0;
      dfs(i, j);
      if (cnt == S) {
        ans = true;
        break;
      }
    }
  }

  if (ans) cout << "YES" << endl;
  else cout << "NO" << endl;
}