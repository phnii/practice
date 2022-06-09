#include <bits/stdc++.h>
using namespace std;

void pirnt_row(int b, int c, int n) {
  char col;
  for (int j = 0; j < n; j++) {
    if ((c + j) % 2 == 0) col = '.';
    else col = '#';
    for (int i = 0; i < b; i++) {
      cout << col;
    }
  }
  cout << endl;
}

int main() {
  int n, a, b; cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a; j++) {
      pirnt_row(b, i, n);
    }
  }
}