#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 505;
const int N = 5005;
ll z[N];
struct edge {
  ll h, c;
} e[maxn];
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld %lld", &e[i].h, &e[i].c);
      sum += e[i].c;
    }
    memset(z, 0, sizeof(z));
    for (int i = 0; i < n; i++) {
      for (int j = sum; j >= e[i].c; j--) {
        z[j] = max(z[j], z[j - e[i].c] + e[i].h); 
      }
    }
    ll ans = 0;
    for (int i = 0; i <= sum; i++) {
      ans = max(ans, z[i] * z[i] - z[i] * i - i * i);
    }
    printf("%lld\n", ans);
  }
  return 0;
}