#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

inline int mul(int a, int b)
{
	return (long long) a * b % 1000;
}
inline int power(int n, int k)
{
	int res = 1;
	while (k) {
		if (k & 1)
			res = mul(res, n);
		n = mul(n, n);
		k >>= 1;
	}
	return res;
}
int main()
{
	int t;
	int kase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		double t = k * log10(n);
		t -= (int)t;
		int ans1 = pow(10, t) * 100;
		int ans2 = power(n, k);
		printf("Case %d: %d ", kase++, ans1);
		if (ans2 >= 100)
			printf("%d\n", ans2);
		else if (ans2 >= 10)
			printf("0%d\n", ans2);
		else
			printf("00%d\n", ans2);
	}
	return 0;
}
