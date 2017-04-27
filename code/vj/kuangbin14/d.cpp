#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	scanf("%d", &t);
	for (int qq = 1; qq <= t; qq++) {
		ll n;
		scanf("%lld", &n);
		ll ans = 0;
		double tt = n;
		ans = ll(sqrt(tt)) + ll(sqrt(tt / 2));
		printf("Case %d: %lld\n", qq, n - ans);
	}
	return 0;
}
