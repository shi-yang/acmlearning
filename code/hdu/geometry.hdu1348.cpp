#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const double PI = acos(-1.0);
struct Point {
	int x, y;
	Point(){}
	Point(int x, int y) : x(x), y(y) {}
	Point operator + (const Point &a) {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) {
		return Point(x - a.x, y - a.y);
	}
	int operator ^ (const Point &a) {
		return x * a.y - y * a.x;
	}
	bool operator < (const Point &a) {
		return x < a.x || x == a.x && y < a.y;
	}
} P[N], d[N];
int det(Point a, Point b)
{
	return a.x * b.y - a.y * b.x;
}
int convexHull(Point *p, Point *ch, int n)
{
	int m = 0;
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		while (m > 1 && det(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
			m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--) {
		while (m > k && det(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
			m--;
		ch[m++] = p[i];
	}
	return n > 1 ? m - 1 : m;
}
double dis(Point a, Point b)
{
	return sqrt(1.0 * ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}
int main()
{
	int t, flag = 0;
	scanf("%d", &t);
	while (t--) {
		if (flag) {
			printf("\n");
		}
		flag = 1;
		int n, l;
		scanf("%d %d", &n, &l);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &P[i].x, &P[i].y);
		}
		int m = convexHull(P, d, n);
		double ans = 0;
		for (int i = 1; i < m; i++) {
			ans += dis(d[i], d[i - 1]);
		}
		ans += dis(d[0], d[m - 1]);
		printf("%.0f\n", ans + 2 * PI * l);
	}
	return 0;
}