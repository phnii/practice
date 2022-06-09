#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, q; cin >> n >> q;
  vector<int> num(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    num[i] = i; // i番には何が入っているか
    pos[i] = i; // iは何番に入っているか
  }

  for (int i = 0; i < q; i++) {
    int x; cin >> x;
    int p0 = pos[x];
    int p1 = p0;
    if (p0 != n)
      p1++;
    else
      p1--;
    int n0 = num[p0];
    int n1 = num[p1];
    swap(num[p0], num[p1]);
    swap(pos[n0], pos[n1]);
  }

  for (int i = 1; i <= n; i++) {
    if (i != 1) cout << " ";
    cout << num[i];
  }
}