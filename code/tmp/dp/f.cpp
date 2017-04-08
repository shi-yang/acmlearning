#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1005;
int dp[maxn][maxn];
int val[maxn], vol[maxn];
int main()
{
  int t;
  cin >> t;
  while (t--) {
    memset(dp, 0, sizeof(dp));
    int n, v;
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
      cin >> val[i];
    for (int i = 1; i <= n; i++)
      cin >> vol[i];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= v; j++) {
        if (j - vol[i] >= 0) {
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vol[i]] + val[i]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    cout << dp[n][v] << endl;
  }
  return 0;
}
