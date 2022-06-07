#include <bits/stdc++.h>
using namespace std;
using line = pair<int, int>;

/* 
  全順列の問題
  1だけを先頭に固定した1~Nについて全順列をについて、
  隣り合う整数をつなぐ辺が存在するかを調べる
  全ての整数が繋がっているときカウントをする
*/

// 引数lで指定した辺が存在しているときtrueを返す
bool search_line(vector<line> v, line l) {
  line l2 = line(l.second, l.first);
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == l || v[i] == l2)
      return true;
  }
  return false;
}

int main() {
  int N, M; cin >> N >> M;
  vector<line> v(M);
  int ans = 0;

  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    line l = line(a, b);
    v.push_back(l);
  }

  vector<int> p(N);
  p[0] = 1;
  for (int i = 1; i < N; i++) {
    p[i] = i + 1;
  }

  do {
    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
      line l = line(p[i], p[i+1]);
      if (search_line(v, l))
        cnt++;
    }
    if (cnt == N - 1)
      ans++;
  } while (next_permutation(p.begin() + 1, p.end()));

  cout << ans;
}