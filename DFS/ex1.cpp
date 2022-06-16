#include <bits/stdc++.h>

using namespace std;

int w, h;
int C[52][52];
int num;

void label(int row, int column) {
  int i, j;
  C[row][column] = num;
  for (i = -1; i <= 1; i++)
    for (j = -1; j <= 1; j++)
      if (C[row+i][column+j] == 1) label(row+i, column+j);
}

int main() {
  int i, j;
  while (1) {
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    for (i = 1; i <= h; i++)
      for (j = 1; j <= w; j++)
        cin >> C[i][j];
    for (j = 0; j <= w + 1; j++)
      C[0][j] = C[h + 1][j] = 0;
    for (i = 1; i <= h; i++)
      C[i][0] = C[i][w + 1] = 0;
    num = 1;
    for (i = 1; i <= h; i++)
      for (j = 1; j <= w; j++)
        if (C[i][j] == 1) {
          num++;
          label(i, j);
        }
    cout << num - 1 << endl;
    for (i = 1; i <= h; i++ ) {
      for(j = 1; j <= w; j++) {
        cout << C[i][j] << " ";
      }
      cout << endl;
    }
  }
}