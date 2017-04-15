#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int main()
{
  string x, y;
  while (cin >> x >> y) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < x. size(); i++) {
      for (int j = 0; j < y.size(); j++) {
        if (x[i] == y[j]) {
          dp[i][j] = max(dp[i][j], ) + 1;
        }
      }
    }    
  }
  return 0;
}