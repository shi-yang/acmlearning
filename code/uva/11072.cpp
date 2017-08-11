#include <bits/stdc++.h>
using namespace std;
struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
	bool operator < (const Point &a) const {
		return x < a.x || x == a.x && y < a.y;
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
} a[100005], ch[100005];
int det(Point a, Point b)
{
	return a.x * b.y - a.y * b.x;
}
int convex_hull(int n)
{
	int m = 0;
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		while (m > 1 && det(ch[m - 1] - ch[m - 2], a[i] - ch[m - 2]) <= 0)
			m--;
		ch[m++] = a[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--) {
		while (m > k && det(ch[m - 1] - ch[m - 2], a[i] - ch[m - 2]) <= 0)
			m--;
		ch[m++] = a[i];
	}
	return n > 1 ? m - 1 : m;
}
int main()
{
	int n, m;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a[i].x, &a[i].y);
		}
		int num = convex_hull(n);
		scanf("%d", &m);
		while (m--) {
			int x, y;
			scanf("%d %d", &x, &y);
			Point o = Point(x, y);
			int ok = 1;
			for (int i = 0; i < num - 1; i++) {
				if (det(ch[i + 1] - ch[i], o - ch[i]) < 0) {
					ok = 0;
					break;
				}
			}
			if (det(ch[0] - ch[num - 1], o - ch[num - 1]) < 0) {
				ok = 0;
			}
			if (ok) {
				puts("inside");
			} else {
				puts("outside");
			}
		}
	}
	return 0;
}