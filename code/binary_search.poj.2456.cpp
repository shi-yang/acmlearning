#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100005;
int x[maxn];
int n, c;
int g(int i)
{
	int cnt = 0;
	int p = x[0];
	for (int j = 1; j < n; j++) {
		if (x[j] - p > i) {
			p = x[j];
			cnt++;
		}
		if (cnt >= c - 1)
			return true;
	}
	return false;
}
int main()
{
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	sort(x, x + n);
	int p = 0;
	int q = x[n - 1] - x[0];
	int m;
	while (p <= q) {
		m = (q + p) >> 1;
		//cout << m << ' ' << p << ' ' << q <<  endl;
		if (g(m))
			p = m + 1;
		else
			q = m - 1;
	}
	printf("%d\n", p);
	return 0;
}
