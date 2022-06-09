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
    int idx = pos[x];
    int cidx; int cnum;
    if (idx == n) {
      cidx = pos[num[idx - 1]];
      cnum = num[cidx];
      swap(num[idx], num[cidx]);
      swap(pos[x], pos[cnum]);
    }
    else {
      cidx = pos[num[idx + 1]];
      cnum = num[cidx];
      swap(num[idx], num[cidx]);
      swap(pos[x], pos[cnum]);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (i != 1) cout << " ";
    cout << pos[i];
  }
}