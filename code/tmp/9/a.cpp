#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll g, l;
	while (~scanf("%lld %lld", &g, &l)) {
		ll a, b;
		ll t = g * l;
		for (a = sqrt((double)t); a > 0; a--) {
			if (t % a == 0) {
				b = t / a;
				break;
			}
		}
		if (a > b)
			swap(a, b);
		printf("%lld %lld\n", a, b);
	}
	return 0;
}
