#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> counter;
vector<int> p_lis;

void dfs(const Graph &G, int v, int p, int cnt) {
  counter[v] += cnt;
  for (auto next_v : G[v]) {
    if (next_v == p) continue;
    dfs(G, next_v, v, cnt);
  }
}

void dfs1(const Graph &G, int v, int p) {
  for (auto next_v : G[v]) {
    if (next_v == p) continue;
    p_lis[next_v] = v;
    dfs1(G, next_v, v);
  }
}

int main() {
  int N, Q; cin >> N >> Q;
  p_lis.resize(N);
  p_lis.assign(N, -1);
  counter.resize(N);
  Graph G(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs1(G, 0, -1);
  for (int i = 0; i < Q; i++) {
    int p, x; cin >> p >> x;
    p--;
    dfs(G, p, p_lis[p], x);
  }

  for (int i = 0; i < N; i++)
    cout << counter[i] << endl;
}