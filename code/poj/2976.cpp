#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const double eps = 1e-7;
const int N = 1005;
int n, k;
double mid;
struct node {
	int a, b;
	bool operator < (const node &op) const {
		return 1.0 * (a - mid * b) > 1.0 * (op.a - mid * op.b);
	}
} e[N];
int main()
{
	while (~scanf("%d %d", &n, &k) && (n + k)) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &e[i].a);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &e[i].b);
		}
		double low = 0.0, high = 1.0;
		double ans = 0;
		while (high - low > eps) {
			mid = (low + high) / 2;
			sort(e, e + n);
			long long suma = 0, sumb = 0;
			for (int i = 0; i < n - k; i++) {
				suma += e[i].a;
				sumb += e[i].b;
			}
			double tmp = 1.0 * suma - mid * sumb;
			ans = 1.0 * suma / sumb;
			if (tmp < 0) {
				high = mid;
			} else {
				low = mid;
			}
		}
		printf("%.f\n", ans * 100);
	}
	return 0;
}