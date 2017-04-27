#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
inline ll power(ll n, ll k)
{
  ll res = 1;
  while (k > 0) {
    if (k & 1)
      res = res * n % 7;
    res = res * n * n % 7;
    k >>= 1;
  }
  return res;
}
char str[10][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);

    int ans = 6;
    for (int i = 1; i <= n; i++) {
      ans += power(i, i);
      ans %= 7;
      cout << "i " << i << "   day:" << str[ans] << endl;
    }
    printf("%s\n", str[ans]);
  }
  return 0;
}