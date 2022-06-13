#include <bits/stdc++.h>
using namespace std;

int make_sequence(int a[], int b[], int c[], int n, int idx, int pat, int k) {
  if (idx == n)
    return 1;
  if (idx == 0) {
    if (pat == 0)
      c[0] = a[0];
    else
      c[0] = b[0];
  } else {
    if (abs(c[idx - 1] - a[idx]) < k) {
      c[idx] = a[idx];
      int res = make_sequence(a, b, c, n, idx + 1, pat, k);
      if (res == 0)
        break;
    }
    if (abs(c[idx - 1] - b[idx]) < k) {
      c[idx] = b[idx];
      make_sequence(a, b, c, n, idx + 1, pat, k);
    }
    else
      return 0;
  }
}

int main() {
  int n, k; cin >> n >> k;
  int a[n], b[n], c[n];

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int  i = 0; i < 2; i++) {
    int res = make_sequence(a, b, c, n, 0, i, k);
    if (res) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}