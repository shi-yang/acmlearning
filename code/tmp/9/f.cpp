#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1001;
ll a, b, n;
int f[N][N << 2];
int t[N];
inline ll power(ll n, ll k, ll mod)
{
	ll res = 1;
	while (k) {
		if (k & 1)
			res = res * n % mod;
		res = res * n * n % mod;
		k >>= 1;
	}
	return res;
}
void init()
{
	f[0] = f[1] = 1;
	for (int i = 0; i < N - 2; i++) {
		f[i][
		f[i + 2] = f[i + 1] + f[i];
	}
}
int main()
{
	//init();
	//cout << f[999] << endl;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &a, &b, &n);
		f[0] = f[1] = 1;
		for (int i = 0; i < n - 2; i++)
			f[i + 2] = (f[i + 1] + f[i]) % n;
		ll res = power(a, b, n);
		printf("%d\n", f[res % (n * n)]);
	}
	return 0;
}
