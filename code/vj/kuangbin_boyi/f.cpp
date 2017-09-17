#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
int f[1000];
int main()
{
  f[0] = 1;
  f[1] = 2;
  int i;
  for (i = 2; f[i] <= inf; i++) {
    f[i] = f[i - 1] + f[i - 2];
    if (f[i] < 0)
      break;
  }
  int n;
  while (~scanf("%d", &n) && n) {
    int p = lower_bound(f, f + i, n) - f;
    if (f[p] != n) {
      puts("First win");
    } else {
      puts("Second win");
    }
  }
  return 0;
}