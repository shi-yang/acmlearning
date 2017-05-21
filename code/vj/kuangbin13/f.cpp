#include <cstdio>
using namespace std;
const int maxn = 100005;
int ans[1005];
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y): x(x), y(y) {}
  Point operator + (const Point & a) const {
    return Point(x + a.x, y + a.y);
  }
  Point operator - (const Point & a) const {
    return Point(x - a.x, y - a.y);
  }
  double operator ^ (const Point & a) const {
    return x * a.y - y * a.x;
  }
};
struct Line {
  Point a, b;
  Line(){}
  Line(Point a, Point b) : a(a), b(b) {}
} line[maxn];
double det(const Point &a, const Point &b)
{
  return a ^ b;
}
int main()
{
  int n;
  while (~scanf("%d", &n) && n) {
    for (int i = 0; i < n; i++) {
      double a, b, c, d;
      scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
      line[i] = Line(Point(a, b), Point(c, d));
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int j;
      for (j = i + 1; j < n; j++) {
        if (det(line[i].a - line[j].a, line[i].b - line[j].a) * det(line[i].a - line[j].b, line[i].b - line[j].b) < 0 &&
            det(line[j].a - line[i].a, line[j].b - line[i].a) * det(line[j].a - line[i].b, line[j].b - line[i].b) < 0)
          break;
      }
      if (j == n)
        ans[sum++] = i + 1;
    }
    printf("Top sticks: ");
    for (int i = 0; i < sum; i++) {
      if (i)  printf(", ");
      printf("%d", ans[i]);
    }
    printf(".\n");
  }
  return 0;
}
