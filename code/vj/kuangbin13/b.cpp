#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 5555;
int n, m, x1, y1, x2, y2;
struct Point {
  int x, y;
  Point(){}
  Point(int x, int y): x(x), y(y) {}
  Point operator - (const Point & b) const {
    return Point(x - b.x, y - b.y);
  }
  Point operator * (const Point & b) const {
    return Point(x * b.x, y * b.y);
  }
  int operator ^ (const Point & b) const {
    return x * b.y - b.x * y;
  }
};
struct Line {
  Point s, e;
  Line() {}
  Line(Point s, Point e) : s(s), e(e) {}
};
Line line[maxn];
int ans[maxn];
int xmult(Point p0, Point p1, Point p2)
{
  return (p1 - p0) ^ (p2 - p0);
}
int main()
{
  bool first = 0;
  while (~scanf("%d", &n) && n) {
    if (first)
      printf("\n");
    first = 1;
    scanf("%d %d %d %d %d", &m, &x1, &y1, &x2, &y2);
    int a, b;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &a, &b);
      line[i] = Line(Point(a, y1), Point(b, y2));
    }
    line[n] = Line(Point(x2, y1), Point(x2, y2));
    memset(ans, 0, sizeof(ans));
    while (m--) {
      scanf("%d %d", &a, &b);
      Point p = Point(a, b);
      int l = 0, r = n;
      int tmp;
      while (l <= r) {
        int m = (l + r) >> 1;
        if (xmult(p, line[m].s, line[m].e) < 0) {
          tmp = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      ans[tmp]++;
    }
    for (int i = 0; i <= n; i++)
      printf("%d: %d\n", i, ans[i]);
  }
  return 0;
}