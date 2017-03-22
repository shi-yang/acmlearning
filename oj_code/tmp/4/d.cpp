#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 60005;
const double eps = 1e-6;
int n;
struct edge {
  int a, v;
} e[maxn];
bool c(double m)
{
  double tmp1 = e[0].a + e[0].v * m;
  double tmp2 = e[0].a - e[0].v * m;
  for (int i = 1; i < n; i++) {
    tmp1 = min(e[i].a + e[i].v * m, tmp1);
    tmp2 = max(e[i].a - e[i].v * m, tmp2);
  }
  return tmp2 >= tmp1;
}
int main()
{
  //freopen("in", "r", stdin);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &e[i].a);
  for (int i = 0; i < n; i++)
    scanf("%d", &e[i].v);
  double l = 0, r = 1e9;
  while (r - l > eps) {
    //printf("%.20lf %.20lf\n", l, r);
    double m = (l + r) / 2.0;
    if (c(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  printf("%.12lf\n", l);
  return 0;
}
