#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

vector<int> d;
vector<int> f;

int t = 2;
void dfs(const Graph &G, int i) {
  for (auto next_v : G[i]) {
    if (d[next_v] == -1) {
      d[next_v] = t;
      t++;
      dfs(G, next_v);
    }
  }
  if (f[i] == -1) {
    f[i] = t;
    t++;
  }
}

int main() {
  int N; cin >> N;
  d.resize(N); f.resize(N);
  d.assign(N, -1); f.assign(N, -1);
  Graph G(N);
  for (int i = 0; i < N; i++) {
    int u; cin >> u;
    int k; cin >> k;
    for (int j = 0; j < k; j++) {
      int v; cin >> v;
      v--;
      G[u - 1].push_back(v);
    }
  }

  d[0] = 1;

  dfs(G, 0);

  for (int i = 0; i < N; i++) {
    printf("%d %d %d\n", i + 1, d[i], f[i]);
  }
}