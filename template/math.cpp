#include <stdio.h>

//最大公约数
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

//素数打表O(nlog(log(n)))
const int maxn = 1000;
bool primes[maxn];
void get_primes()
{
	memset(primes, true, sizeof(primes));
	for (int i = 2; i <= maxn; i++)
		if (primes[i]) {
			for (int j = i * i; j <= maxn; j++) {
				primes[j] = false;
			}
		}
}


//O(n)
int get_primes()
{
	int n;
	vector<int> primes;
	bool is_primes[n + 1];
	memset(is_primes, true, sizeof(is_primes));
	for (int i = 2; i <= n; i++) {
		if (is_primes[i])
			primes.push_back(i);
		for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
			is_primes[i * primes[j]] = false;
			if (i % primes[j] == 0) {
				break;
			}
		}
	}
}

void ex_gcd(int a, int b, int &d, int &x, int &y)
{
	if (!b) {
		x = 1, y = 0, d = a;
	} else {
		gcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}


typedef long long ll;
// a * b % c
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
// a ^ b % c
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
// 判断素数
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
// 质因数分解
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


//FFT O(nlogn)
int rev(int id, int len)
{
	int res = 0;
	for (int i = 0; (1 << i) < len; i++) {
		res <<= 1;
		if (id & (1 << i))
			res |= 1;
	}
	return res;
}
void fft(vector<complex<double> > &a, int len, int dft)
{
	vector<complex<double> > tmp;
	tmp.resize(len);
	for (int i = 0; i < len; i++) {
		tmp[rev(i, len)] = a[i];
	}
	for (int s = 1; 1 << s <= len; s++) {
		int m = 1 << s;
		complex<double> wm = complex<double>(cos(dft * 2 * pi / m), sin(dft * 2 * pi / m));
		for (int k = 0; k < len; k += m) {
			complex<double> w = complex<double>(1, 0);
			for (int j = 0; j < (m >> 1); j++) {
				complex<double> t = w * tmp[k + j + (m >> 1)];
				complex<double> u = tmp[k + j];
				tmp[k + j] = u + t;
				tmp[k + j + (m >> 1)] = u - t;
				w = w * wm;
			}
		}
	}
	if (dft == -1) {
		for (int i = 0; i < len; i++) {
			tmp[i] = complex<double>(tmp[i].real() / len, tmp[i].imag() / len);
		}
	}
	a = tmp;
}
