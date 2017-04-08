#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 305;
const int inf = 1e9;
int n, m;
int c[maxn];
int d[maxn][maxn];
int main()
{
  scanf("%d %d", &n, &m);
  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j < maxn; j++) {
      d[i][j] = inf;
    }
    d[i][i] = 0;
  }
  while (m--) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j < x; j++) {
      scanf("%d", &c[j]);
    }
    for (int j = 0; j < x; j++) {
      for (int k = j + 1; k < x; k++) {
        d[c[j]][c[k]] = d[c[k]][c[j]] = 1;
      }
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int ans = inf;
  for (int i = 1; i <= n; i++) {
    int t = 0;
    for (int j = 1; j <= n; j++) {
      t += d[i][j];
    }
    ans = min(ans, t);
  }
  printf("%d\n", 100 * ans / (n - 1));
  return 0;
}
