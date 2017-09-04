#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
  Point operator - (const Point &op) const {
    return (Point){x - op.x, y - op.y};
  }
};
double cross(Point a, Point b)
{
  return a.x * b.y - a.y * b.x;
}
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    double sum = 0;
    double sum_x = 0, sum_y = 0;
    Point a, b, c;
    scanf("%lf %lf", &a.x, &a.y);
    scanf("%lf %lf", &b.x, &b.y);
    for (int i = 2; i < n; i++) {
      scanf("%lf %lf", &c.x, &c.y);
      double s = cross(b - a, c - a) / 2;
      sum += s;
      sum_x += (a.x + b.x + c.x) * s;
      sum_y += (a.y + b.y + c.y) * s;
      b = c;
    }
    printf("%.2lf %.2lf\n", sum_x / sum / 3.0, sum_y / sum / 3.0);
  }
  return 0;
}