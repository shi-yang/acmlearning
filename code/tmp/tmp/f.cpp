#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const double eps = 1e-7;
int n;
float k;
int a[maxn];
long long sum;
bool check(double m)
{
  double mo = 0;
  for (int i = 0; i < n; i++) {
    
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  int cas = 1;
  while (t--) {
    cin >> n >> k;
    sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      sum += a[i];
    }
    sort(a, a + n);
    double l = 0, r = 100005;
    while (r - l > eps) {
      double m = (r + l) / 2.0;
      if (check(m)) {
        l = m;
      } else {
        r = m;
      }
    }
    printf("Case #%d: %f\n", cas++, l);
  }
  return 0;
}