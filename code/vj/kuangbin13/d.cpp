#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 15;
int n;
struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y) {}
  Point operator - (const Point &a) const {
    return Point(x - a.x, y - a.y);
  }
  int operator ^ (const Point &a) const {
    return x * a.y - a.x * y;
  }
};

struct Line {
  Point s, e;
  Line() {}
  Line(Point s, Point e) : s(s), e(e) {}
} line[maxn];

int xmult(Point p0, Point p1, Point p2)
{
  return (p1 - p0) ^ (p2 - p0);
}

int main()
{
  printf("INTERSECTING LINES OUTPUT\n");
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) {
      Point a, b;
      scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);
      line[i] = Line(a, b);
    }
    
  }
  printf("END OF OUTPUT\n");
  return 0;
}
