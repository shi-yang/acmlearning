#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int c[10005];
int y[10005];
int main()
{
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> y[i];
	}
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		c[i] = min(c[i - 1] + s, c[i]);
	}
	for (int i = 0; i < n; i++) {
		ans += c[i] * y[i];
	}
	printf("%lld\n", ans);
	return 0;
}
