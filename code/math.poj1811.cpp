#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
inline ll mul(ll a, ll b, ll c)
{
	ll res = 0;
	a %= c, b %= c;
	while (b) {
		if (b & 1) {
			res += a;
			if (res >= c) res -= c;
		}
		a <<= 1;
		if (a >= c)
			a -= c;
		b >>= 1;
	}
	return res;
}
inline ll power(ll n, ll k, ll m)
{
	ll res = 1;
	while (k) {
		if (k & 1)
			res = mul(res, n, m);
		n = mul(n, n, m);
		k >>= 1;
	}
	return res;
}
bool check(ll a, ll x, ll n, ll t)
{
	ll res = power(a, x, n);
	ll last = res;
	while (t--) {
		res = mul(res, res, n);
		if (res == 1 && last != 1 && last != n - 1)
			return true;
		last =res;
	}
	if (res != 1)
		return true;
	return false;
}
bool miller_rabin(ll n, ll s)
{
	if (n < 2)	return false;
	if (n == 2)	return true;
	if ((n & 1) == 0)	return false;
	ll x = n - 1;
	ll t = 0;
	while ((x & 1) == 0) {
		t++, x >>= 1;
	}
	while (s--) {
		ll a = rand() % (n - 1) + 1;
		if (check(a, x, n, t))
			return false;
	}
	return true;
}

ll factor[10000];
int cnt;
ll gcd(ll a, ll b)
{
	if (a == 0)	return 1;
	if (a < 0)	return gcd(-a, b);
	while (b) {
		ll t = a % b;
		a = b, b = t;
	}
	return a;
}
ll pollard_rho(ll n, ll c)
{
	ll i = 1, k = 2;
	ll x = rand() % n;
	ll y = x;
	while (1) {
		i++;
		x = (mul(x, x, n) + c) % n;
		ll d = gcd(y - x, n);
		if (d != 1 && d != n)	return d;
		if (y == x)	return n;
		if (i == k) {
			y = x;
			k <<= 1;
		}
	}
}
void findfac(ll n)
{
	if (miller_rabin(n, 20)) {
		factor[cnt++] = n;
		return ;
	}
	ll p = n;
	while (p >= n)
		p = pollard_rho(p, rand() % (n - 1) + 1);
	findfac(p);
	findfac(n / p);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		if (miller_rabin(n, 20)) {
			printf("Prime\n");
		} else {
			cnt = 0;
			findfac(n);
			ll ans = factor[0];
			for (int i = 1; i < cnt; i++)
				ans = min(ans, factor[i]);
			printf("%lld\n", ans);
		}
	}
	return 0;
}
