#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[10005];
int f[10005];
int main()
{
  int k;
  while (scanf("%d", &k) && k) {
    bool flag = true;
    for (int i = 0; i < k; i++) {
      scanf("%d", &a[i]);
      if (a[i] >= 0)
        flag = false;
    }
    if (flag) {
      printf("%d %d %d\n", 0, a[0], a[k - 1]);
      continue;
    }
    if (k == 1) {
      printf("%d %d %d\n", a[0], a[0], a[0]);
      continue;
    }
    memset(f, 0, sizeof(f));
    int sum = f[0] = a[0], ep = 0, bp;
    for (int i = 1; i < k; i++) {
      if (f[i - 1] < 0) {
        f[i] = a[i];
      } else {
        f[i] = f[i - 1] + a[i];
      }
      if (sum < f[i]) {
        sum = f[i];
        ep = i;
      }
    }
    int t = 0;
    for (int i = ep; i >= 0; i--) {
      t += a[i];
      bp = i;
      if (t == sum) {
        break;
      }
    }
    printf("%d %d %d\n", sum, a[bp], a[ep]);
  }
  return 0;
}
