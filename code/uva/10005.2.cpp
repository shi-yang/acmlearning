#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int N = 105;
pair<double, double> p[N];
double dis(pair<double, double> a, pair<double, double> b)
{
  return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
int main()
{
  int n;
  while (~scanf("%d", &n) && n) {
    for (int i = 0; i < n; i++) {
      scanf("%lf %lf", &p[i].first, &p[i].second);
    }
    double r;
    scanf("%lf", &r);
    double tmp = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        tmp = max(tmp, dis(p[i], p[j]));
      }
    }
    cout << tmp / 2  << endl;
    if (tmp / 2 < r + eps) {
      puts("The polygon can be packed in the circle.");
    } else {
      puts("There is no way of packing that polygon.");
    }
  }
  return 0;
}