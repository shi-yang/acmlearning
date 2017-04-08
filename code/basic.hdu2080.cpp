#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--) {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double a = sqrt(x1 * x1 + y1 * y1);
    double b = sqrt(x2 * x2 + y2 * y2);
    double c = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double t = 1.0 * (a * a + b * b - c * c) / (2.0 * a * b);
    double ans = acos(t) * 180.0 / 3.141592653;
    printf("%.2lf\n", ans);
  }
  return 0;
}
