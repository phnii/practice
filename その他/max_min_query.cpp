#include <bits/stdc++.h>
using namespace std;

int main() {
  int Q; cin >> Q;
  multiset<int> st;
  /* multisetはデータの追加・削除・検査は O(log N) */

  while(Q--) {
    int s; cin >> s;
    if (s == 1) {
      int x; cin >> x;
      st.insert(x);
    } else if (s == 2) {
      int x, c; cin >> x >> c;
      while (c-- && st.find(x) != st.end()) {
        st.erase(st.find(x));
      }
    } else {
      cout << *st.rbegin() - *st.begin() << endl;
    }
  }
}