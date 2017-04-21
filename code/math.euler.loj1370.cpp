#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1000005;
int a[N];
int primes[N];
int main()
{
	int t;
	int cas = 1;
	memset(primes, -1, sizeof(primes));
	primes[1] = 0;
	for (int i = 2; i * i <= N; i++) {
		if (primes[i])
			for (int j = i * i; j <= N; j += i)
				primes[j] = 0;
	}
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		ll ans = 0;
		while (n--) {
			int x;
			scanf("%d", &x);
			for (int i = x + 1; ; i++)
				if (primes[i]) {
					ans += i;
					break;
				}
		}
		printf("Case %d: %lld Xukha\n", cas++, ans);
	}
	return 0;
}
