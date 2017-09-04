#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int N = 105;
struct Point {
  double x, y;
} p[N];
int n;
double dis(Point a, Point b)
{
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
Point center(Point aa, Point bb, Point cc)
{
  Point res;
  double a = bb.x - cc.x, b = bb.y - cc.y, c = (bb.x * bb.x - cc.x * cc.x + bb.y * bb.y - cc.y * cc.y) / 2;
  double d = aa.x - bb.x, e = aa.y - bb.y, f = (aa.x * aa.x - bb.x * bb.x + aa.y * aa.y - bb.y * bb.y) / 2;
  res.x = (c * e - b * f) / (a * e - b * d);
  res.y = (a * f - d * c) / (a * e - b * d);
  return res;
}
double cover_circle()
{
  random_shuffle(p, p + n);
  double r = 0.0;
  Point c = p[0];
  for (int i = 1; i < n; i++) {
    if (dis(p[i], c) > r + eps) {
      c = p[i], r = 0.0;
      for (int j = 0; j < i; j++) {
        if (dis(p[j], c) > r + eps) {
          c.x = (p[i].x + p[j].x) / 2;
          c.y = (p[i].y + p[j].y) / 2;
          r = dis(p[j], c);
          for (int k = 0; k < j; k++) {
            if (dis(p[k], c) > r + eps) {
              c = center(p[i], p[j], p[k]);
              r = dis(p[i], c);
            }
          }
        }
      }
    }
  }
  return r;
}
int main()
{
  while (~scanf("%d", &n) && n) {
    for (int i = 0; i < n; i++) {
      scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    double r;
    scanf("%lf", &r);
    if (cover_circle() < r + eps) {
      printf("The polygon can be packed in the circle.\n");
    } else {
      printf("There is no way of packing that polygon.\n");
    }
  }
  return 0;
}