#include <iostream>
#include <cstdio>
using namespace std;
const double eps = 1e-8;
const int N = 1e5 + 5;
int n;
int sum[1005];
struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	Point operator + (const Point & a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point & a) const {
		return Point(x - a.x, y - a.y);
	}
	double operator * (const Point & a) const {
		return x * a.x + y * a.y;
	}
	double operator ^ (const Point & a) const {
		return x * a.y - y * a.x;
	} 
};
struct Line {
	Point a, b;
	Line() {}
	Line(Point a, Point b) : a(a), b(b) {}
} line[N];
double det(const Point &a, const Point &b, const Point &c)
{
	return (b - a) ^ (c - a);
}
int main()
{
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) {
			double a, b, c, d;
			scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
			line[i] = Line(Point(a, b), Point(c, d));
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int j;
			for (j = i + 1; j < n; j++) {
				if (det(line[j].a, line[j].b, line[i].b) * det(line[j].a, line[j].b, line[i].a) < 0
					&& det(line[i].a, line[i].b, line[j].a) * det(line[i].a, line[i].b, line[j].b) < 0)
					break;
			}
			if (j == n) {
				sum[ans++] = i + 1;
			}
		}
		printf("Top sticks: ");
		for (int i = 0; i < ans; i++) {
			if (i)
				printf(", ");
			printf("%d", sum[i]);
		}
		puts(".");
	}
	return 0;
}
