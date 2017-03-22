#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long sum[maxn];
long long sumtmp = 0;
int n;
int main()
{
  //freopen("data.in", "r", stdin);
  int k;
  scanf("%d%d", &n, &k);
  memset(sum,0,sizeof(sum));
  for (int i = 1; i <= n; i++) {
    int val;
    scanf("%I64d", &val);
    sum[i]=sum[i-1]+val;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      long long tmp = sum[j] - sum[i - 1];
      if (tmp == 0)
        continue;
      while (tmp % k == 0) {
        tmp /= k;
      }
      if (tmp == 1) {
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
