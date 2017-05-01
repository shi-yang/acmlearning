#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const int maxn = 105;
int n;
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y): x(x), y(y) {}
  Point operator - (const Point &a) const {
    return Point(x - a.x, y - a.y);
  }
  double operator ^ (const Point &a) const {
    return x * a.y - a.x * y;
  }
};
struct Seg {
  Point s, e;
  Seg() {}
  Seg(Point s, Point e) : s(s), e(e) {}
} seg[maxn];
double mult(Point p0, Point p1, Point p2)
{
  return (p1 - p0) ^ (p2 - p0);
}
bool check(Point a, Point b)
{
  if (fabs(a.x-b.x) < eps && fabs(a.y-b.y) < eps) return false;
  for (int i = 0; i < n; i++) {
    if (mult(seg[i].s, a, b) * mult(seg[i].e, a, b) > eps) {
      return false;
    }
  }
  return true;
}
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      Point a, b;
      scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);
      seg[i] = Seg(a, b);
    }
    if (n < 3) {
      printf("Yes!\n");
      continue;
    }
    bool ok = false;
    for (int i = 0; i < n && !ok; i++) {
      for (int j = i + 1; j < n; j++) {
        if (check(seg[i].s, seg[j].e) ||
            check(seg[i].e, seg[j].e) ||
            check(seg[i].s, seg[j].s) ||
            check(seg[i].e, seg[j].s)) {
          ok = true;
          break;
        }
      }
    }
    if (ok)
      printf("Yes!\n");
    else
      printf("No!\n");
  }
  return 0;
}
