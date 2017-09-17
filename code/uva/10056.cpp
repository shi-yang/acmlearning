#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    double p;
    scanf("%d %lf %d", &n, &p, &k);
    double ans = 0;
    for (int i = 0; i < 100; i++) {
      ans += pow(1 - p, k - 1 + i * n) * p;
    }
    printf("%.4lf\n", ans);
  }
  return 0;
}