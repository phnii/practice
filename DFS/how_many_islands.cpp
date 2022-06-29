#include <bits/stdc++.h>
using namespace std;

int w, h;
vector<vector<int>> field;
vector<vector<bool>> seen;
int ans = 0;

void dfs(int x, int y) {
  seen[x][y] = true;
  
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      int nx = x + i;
      int ny = y + j;
      if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
      if (seen[nx][ny] == true) continue;
      if (field[nx][ny] == 0) continue;

      dfs(nx, ny);
    }
  }
}

int main() {
  cin >> w >> h;
  field.assign(h, vector<int>(w));
  seen.assign(h, vector<bool>(w, false));
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> field[i][j];

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (field[i][j] == 1) {
        if (seen[i][j] != true) {
          dfs(i, j);
          ans++;
        }
      }
    }
  }

  cout << ans << endl;
}