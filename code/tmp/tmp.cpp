#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int w[maxn], a[maxn];
int dp[maxn][maxn];
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, v;
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
      scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= v; j++) {
        if (j > w[i]) {
          dp[i][j] = max(dp[i][j], dp[i][j - w[i]] + a[i]);
        }
      }
    }
  }
	return 0;
}
