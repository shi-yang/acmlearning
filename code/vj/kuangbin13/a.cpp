#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m, x1, y1, x2, y2;
const int maxn = 5555;
struct Point {
	int x, y;
	Point() {}
	Point(int x, int y): x(x), y(y) {}
	Point operator - (const Point &b) const {
		return Point(x - b.x, y - b.y);
	}
	int operator * (const Point &b) const {
		return x * b.x + y * b.y;
	}
	int operator ^ (const Point &b) const {
		return x * b.y - b.x * y;
	}
};
struct Line {
	Point s, e;
	Line() {}
	Line(Point s, Point e): s(s), e(e) {}
};
Line line[maxn];
int ans[maxn];
int xmulti(Point p0, Point p1, Point p2)
{
	return (p2 - p0) ^ (p1 - p0);
}
int main()
{
	int li = 0;
	while (~scanf("%d", &n) && n) {
		memset(ans, 0, sizeof(ans));
		scanf("%d %d %d %d %d", &m, &x1, &y1, &x2, &y2);
		int u, l;
		if (li)
			printf("\n");
		li = 1;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &u, &l);
			line[i] = Line(Point(u, y1), Point(l, y2));
		}
		line[n] = Line(Point(x1, y1), Point(x2, y2));
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &u, &l);
			Point p = Point(u, l);
			int l = 0, r = n, tmp;
			while (l <= r) {
				int m = (l + r) >> 1;
				if (xmulti(p, line[m].s, line[m].e) < 0)
					l = m + 1;
				else {
					tmp = m;
					r = m - 1;
				}
			}
			ans[tmp]++;
		}
		for (int i = 0; i <= n; i++) {
			printf("%d: %d\n", i, ans[i]);
		}
	}
	return 0;
}
