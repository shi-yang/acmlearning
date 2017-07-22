#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
	bool operator < (const Point & rhs) const {
		return x < rhs.x || x == rhs.x && y < rhs.y;
	}
};
multiset<Point> s;
multiset<Point>::iterator it;
int main()
{
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		if (cas != 1)
			putchar('\n');
		printf("Case #%d:\n", cas);
		s.clear(); 
		int n;
		scanf("%d", &n);
		while (n--) {
			int x, y;
			scanf("%d %d", &x, &y);
			Point p = (Point){x, y};
			it = s.lower_bound(p);
			if (it == s.begin() || (--it)->y > y) {
				s.insert(p);
				it = s.upper_bound(p);
				while (it != s.end() && it->y >= y)
					s.erase(it++);
			}
			printf("%d\n", s.size());
		}
	}
	return 0;
}