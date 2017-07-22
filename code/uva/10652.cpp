#include <bits/stdc++.h>
using namespace std;
const int N = 605;
struct Point {
	double x, y;
	Point(){}
	Point(double x, double y) : x(x), y(y) {}
	bool operator < (const Point &a) const {
		return x < a.x || x == a.x && y < a.y;
	}
	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
} p[N << 2], ch[N << 1];
double cross(Point a, Point b)
{
	return a.x * b.y - a.y * b.x;
}
int convel(Point * a, int n, Point *ch)
{
	int m = 0;
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		while (m > 1 && cross(ch[m - 1] - ch[m - 2], a[i] - ch[m - 2]) <= 0)
			m--;
		ch[m++] = a[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--) {
		while (m > k && cross(ch[m - 1] - ch[m - 2], a[i] - ch[m - 2]) <= 0)
			m--;
		ch[m++] = a[i];
	}
	return n > 1 ? m - 1 : m;
}
double polygon(Point *a, int n)
{
	double s = 0;
	for (int i = 1; i < n - 1; i++) {
		s += cross(a[i] - a[0], a[i + 1] - a[0]);
	}
	return s / 2;
}
Point rotate(Point a, double rad)
{
	return Point(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad));
}
double torad(double deg)
{
	return deg / 180 * acos(-1.0);
}
int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n;
		scanf("%d", &n);
		double s = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			double x, y, w, h, ang;
			scanf("%lf %lf %lf %lf %lf", &x, &y, &w, &h, &ang);
			ang = -torad(ang);
			Point o(x, y);
			p[cnt++] = o + rotate(Point(-w / 2, -h / 2), ang);
			p[cnt++] = o + rotate(Point(w / 2, -h / 2), ang);
			p[cnt++] = o + rotate(Point(-w / 2, h / 2), ang);
			p[cnt++] = o + rotate(Point(w / 2, h / 2), ang);
			s += w * h;
		}
		int m = convel(p, cnt, ch);
		double sum_s = polygon(ch, m);
		printf("%.1lf %%\n", s * 100 / sum_s);
	}
	return 0;
}