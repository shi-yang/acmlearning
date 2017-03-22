#include <iostream>
using namespace std;
int n, sum;
int a[15];
int vis[15];
int tmp[15][15];
int cnt, flag;
int dfs(int x)
{
  if (x == n) {
    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j <= i; j++) {
        if (i == n - 2) {
          tmp[i][j] = a[j] + a[j + 1];
        } else {
    			tmp[i][j] = tmp[i + 1][j] + tmp[i + 1][j + 1];
        }
      }
    }
    if (tmp[0][0] == sum) {
      flag = 1;
    }
    return true;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    if (flag) {
      return true;
    }
    vis[i] = 1;
    a[x] = i;
    dfs(x + 1);
    vis[i] = 0;
  }
  return false;
}
int main()
{
  cin >> n >> sum;
  flag = 0;
  dfs(0);
  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i != n - 1)
      cout << ' ';
  }
  cout << endl;
  return 0;
}
