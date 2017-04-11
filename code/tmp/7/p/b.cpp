#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll power(ll x, ll n, ll mod)
{
  ll res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
int main()
{
  int n, k, tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    scanf("%d %d", &n, &k);
    double first = 1.0 * k * log10(n * 1.0);
    first -= (long long) first;
    printf("Case %d: %d ", qq, int(pow(10, first) * 100));
    int second = power(n, k, 1000);
    if (second >= 100) {
      printf("%d\n", second);
    } else if (second > 10) {
      printf("0%d\n", second);
    } else {
      printf("00%d\n", second);
    }
  }
  return 0;
}
