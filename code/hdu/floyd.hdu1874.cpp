#include <bits/stdc++.h>
using namespace std;
const int inf = 1e8 + 5;
const int maxn = 205;
int n, m;
int mp[205][205];
int main()
{
  while (cin >> n >> m) {
    int a, b, x;
    for (int i = 0; i < maxn; i++) {
      for (int j = 0; j < maxn; j++) {
        mp[i][j] = i == j ? 0 : inf;
      }
    }
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> x;
      if (mp[a][b] > x)
        mp[a][b] = mp[b][a] = x;
    }
    int s, t;
    cin >> s >> t;
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (mp[i][j] > mp[i][k] + mp[k][j])
            mp[i][j] = mp[i][k] + mp[k][j];
        }
      }
    }
    if (mp[s][t] == inf)
      cout << -1 << endl;
    else
      cout << mp[s][t] << endl;
  }
  return 0;
}
