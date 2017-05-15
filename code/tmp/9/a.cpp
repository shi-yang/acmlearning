#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
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
inline ll power(ll n, ll k, ll mod) {
  ll res = 1;
  while (k) {
    if (k & 1)
      res = mul(res, n, mod);
    k >>= 1;
    n = mul(n, n, mod);
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
    last = res;
  }
  if (res != 1)
    return true;
  return false;
}
bool miller_rabin(ll n, int s)
{
  if (n < 2)  return false;
  if (n == 2) return true;
  if ((n & 1) == 0) return false;
  ll t = 0, x = n - 1;
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
map<ll, int> factor;
ll gcd(ll a, ll b)
{
  if (a == 0) return 1;
  if (a < 0)  return gcd(-a, b);
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
  for (;;) {
    i++;
    x = (mul(x, x, n) + c) % n;
    ll d = gcd(y - x, n);
    if (d != 1 && d != n) return d;
    if (y == x) return n;
    if (i == k) {
      y = x;
      k <<= 1;
    }
  }
}
void findfac(ll n)
{
  if (miller_rabin(n, 40)) {
    factor[n]++;
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
  ll g, l;
  while (~scanf("%lld %lld", &g, &l)) {
    ll t = l / g;
    if (t == 1) {
      printf("%lld %lld\n", g, g);
      continue;
    }
    factor.clear();
    findfac(t);
    vector<ll> em;
    for (map<ll, int>::iterator it = factor.begin(); it != factor.end(); it++) {
      ll v = 1;
      while (it->second--) {
        v *= it->first;
      }
      em.push_back(v);
    }
    ll a = em[0], b = t / a;
    ll mi = a + b;
    for (int i = 1; i < em.size(); i++) {
      if (mi > em[i] + t / em[i]) {
        a = em[i], b = t / em[i];
        mi = a + b;
      }
    }
    if (a > b)
      swap(a, b);
    printf("%lld %lld\n", a * g, b * g);
  }
  return 0;
}