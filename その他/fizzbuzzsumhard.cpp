#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

long long lcm(long long a, long long b) {
  return a * b / gcd(a, b);
}

int main() {
  long long n, a, b; cin >> n >> a >> b;
  long long sum = n * (n + 1) / 2;
  long long sum_a = a * (n / a) * (n / a + 1) / 2;
  long long sum_b = b * (n / b) * (n / b + 1) / 2;
  long long lcm_ab = lcm(a, b);
  long long sum_lcm = lcm_ab * (n / lcm_ab) * (n / lcm_ab + 1) / 2;
  sum = sum - sum_a - sum_b + sum_lcm;
  cout << sum << endl;
}