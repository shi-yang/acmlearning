#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-9;
double a[10005];
int n, k;
bool ck(double m) {
  int tmp = k;
  for (int i = 0; i < n; i++) {
    tmp -= int(a[i] / m);
  }
  return tmp <= 0;
}
int main()
{
  freopen("in", "r", stdin);
  while (~scanf("%d%d", &n, &k) && (n + k)) {
    double sum = 0;
    for (int i = 0; i < n; i++)
      scanf("%lf", &a[i]), sum += a[i];
    double ans;
    if (0.01 * k > sum) {
      ans = 0;
    } else {
      double l = 0, r = sum / k;
      while (r - l > eps) {
        double m = l + (r - l) / 2.0;
        ans = m;
        if (ck(m)) {
          l = m;
        } else {
          r = m;
        }
      }
    }
    printf("%.2lf\n", floor(ans * 100) / 100);
  }
  return 0;
}
