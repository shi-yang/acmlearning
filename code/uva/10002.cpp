#include <bits/stdc++.h>
using namespace std;
const int N = 105;
struct Point {
  double x, y;
  Point operator - (const Point &a) const {
    return (Point){x - a.x, y - a.y};
  }
  bool operator < (const Point &a) const {
    return x < a.x || x == a.x && y < a.y;
  }
} p[N], ch[N];
double cross(Point a, Point b)
{
  return a.x * b.y - a.y * b.x;
}
int convex_hull(int n)
{
  int m = 0;
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    while (m > 1 && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) {
      m--;
    }
    ch[m++] = p[i];
  }
  int k = m;
  for (int i = n - 2; i >= 0; i--) {
    while (m > k && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) {
      m--;
    }
    ch[m++] = p[i];
  }
  return n > 1 ? m - 1: m;
}
int main()
{
  int n;
  while (~scanf("%d", &n) && n > 2) {
    for (int i = 0; i < n; i++)
      scanf("%lf %lf", &p[i].x, &p[i].y);
    int m = convex_hull(n);
    double sum = 0, sum_x = 0, sum_y = 0;
    for (int i = 2; i < m; i++) {
      double s = cross(ch[i - 1] - ch[0], ch[i] - ch[0]);
      sum += s;
      sum_x += (ch[i].x + ch[i - 1].x + ch[0].x) * s;
      sum_y += (ch[i].y + ch[i - 1].y + ch[0].y) * s;
    }
    printf("%.3lf %.3lf\n", sum_x / sum / 3, sum_y / sum / 3);
  }
  return 0;
}