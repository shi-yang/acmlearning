
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
}

```cpp
int convex_hell(Point *a, Point *ch, int n)
{
	int m = 0;
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		while (m > 0 && det(ch[i - 1] - ch[i - 2], a[i] - ch[i - 2]) <= 0)
			m--;
		ch[m++] = a[i];
	}
	int k = m;
	for (int i = n - 1; i >= 0; i--) {
		while (m > k && det(ch[i - 1] - ch[i - 2], a[i] - ch[i - 2]) <= 0)
			m--;
		ch[m++] = a[i];
	}
	return n > 1 ? m - 1 : m;
}
```