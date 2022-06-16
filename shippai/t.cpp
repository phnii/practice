#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  int length;
};

using Graph = vector<vector<Edge>>;

int N;

int color[100000ll];

void dfs(const Graph &G, int v, int cur) {
  color[v] = cur;
  for (auto next_v : G[v]) {
    if (color[next_v.to] != -1) continue;
    if (next_v.length % 2 == 0) {
      dfs(G, next_v.to, cur);
    } else {
      dfs(G, next_v.to, 1 - cur);
    }
  }
}

int main() {
  cin >> N;
  Graph G(N);
  for (int i = 0; i < 50; i++)
    color[i] = -1;

  for (int i = 0; i < N - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    Edge e1 = {v, w};
    Edge e2 = {u, w};
    G[u].push_back(e1);
    G[v].push_back(e2);
  }
  dfs(G, 0, 0);

  for (int i = 0; i < N; i++) {
    cout << color[i] << endl;
  }
}