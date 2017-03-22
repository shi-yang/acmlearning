#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100005;
int f[maxn];
int v[maxn];
int main()
{
  int t;
  freopen("data.in", "r", stdin);
  scanf("%d", &t);
  int cas = 1, flag = false;
  while (t--) {
    if (flag)
      printf("\n");
    flag = true;
    printf("Case %d:\n", cas++);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    memset(f, 0, sizeof(f));
    int sum = f[0] = v[0], sp = 0, ep = 0;
    for (int i = 1; i < n; i++) {
      if (f[i - 1] < 0) {
        f[i] = v[i];
      } else {
        f[i] = f[i - 1] + v[i];
      }
      if (sum < f[i]) {
        sum = f[i];
        ep = i;
      }
    }
    int t = 0;
    for (int i = ep; i >= 0; i--) {
      t += v[i];
      if (t == sum) {
        sp = i;
      }
    }
    printf("%d %d %d\n", sum, sp + 1, ep + 1);
  }
  return 0;
}
