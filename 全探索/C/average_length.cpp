#include <bits/stdc++.h>
using namespace std;
using point = pair<int, int>; // (x, y)

long long factorial(long long a) {
  if (a == 0)
    return 1;
  else
    return a * factorial(a - 1);
}

double get_distance(point p1, point p2) {
  long x1, y1, x2, y2, dx, dy;
  long double L;
  x1 = p1.first; y1 = p1.second;
  x2 = p2.first; y2 = p2.second;
  dx = x1 - x2; dy = y1 - y2;
  L = sqrt(dx * dx + dy * dy);
  return L;
}
 
int main() {
  int N; cin >> N;
  vector<point> v(N);
  long double total = 0;
  long long cnt = 0;

  for (int i = 0; i < N; i++) {
    int x; int y;
    cin >> x >> y;
    v[i].first = x;
    v[i].second = y;
  }

  for (int j = 0; j < factorial(N); j++) {
    long double sum = 0;
    for (int i = 0; i < N - 1; i++) {
      long double d = get_distance(v[i], v[i + 1]);
      sum += d;
    }
    total += sum;
    cnt++;
    next_permutation(v.begin(), v.end());
  }

  long double ans = total / cnt;
  printf("%.10Lf\n", ans);
}