#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double EPS = 1e-9;
const int N = 10;
int sgn(double x)
{
	if (fabs(x) < EPS)
		return 0;
	return x < 0 ? -1 : 1;
}
struct Point {
	double x, y;
	Point(){}
	Point(double x, double y): x(x), y(y) {}
	void read() {
		scanf("%lf %lf", &x, &y);
	}
	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
} P[N];
double cross(Point a, Point b)
{
	return a.x * b.y - a.y * b.x;
}
struct Line {
	Point s, e;
	Line(){}
	Line(Point a, Point b) {
		s = a, e = b;
	}
	pair<Point, int> operator & (const Line &b) const {
		Point res = s;
		if (sgn(cross(s - e, b.s - b.e)) == 0) {
			return sgn(cross(b.s - s, b.e - s)) ? make_pair(res, 1) : make_pair(res, 0);
		}
		double t = 1.0 * cross(s - b.s, b.s - b.e) / cross(s - e, b.s - b.e);
		res.x += (e.x - s.x) * t;
		res.y += (e.y - s.y) * t;
		return make_pair(res, 2);
	}
} line[2];
int main()
{
	printf("INTERSECTING LINES OUTPUT\n");
	int n;
	scanf("%d", &n);
	while (n--) {
		for (int i = 1; i <= 4; i++) {
			P[i].read();
		}
		line[0] = Line(P[1], P[2]);
		line[1] = Line(P[3], P[4]);
		pair<Point, int> ans = line[0] & line[1];
		if (ans.second == 0) {
			printf("LINE\n");
		} else if (ans.second == 1) {
			printf("NONE\n");
		} else {
			printf("POINT %.2lf %.2lf\n", ans.first.x, ans.first.y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}