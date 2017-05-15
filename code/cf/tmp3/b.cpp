#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, h;
  cin >> n >> h;
  double s = 1.0 * h / n;
  double t = s;
  for (int i = 0; i < n - 1; i++) {
    double ans = sqrt(1.0 * s * h);
    s += t;
    printf("%.12llf\n", ans);
  }
  return 0;
}