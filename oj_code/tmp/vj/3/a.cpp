#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int a[maxn];
int main()
{
  memset(a, 0, sizeof(a));
  int n, m, z;
  cin >> n >> m >> z;
  int ans = 0;
  for (int i = 1; i * n <= z; i++) {
    a[i * n] = 1;
  }
  for (int i = 1; i * m <= z; i++) {
    if (a[i * m])
      ans++;
  }
  cout << ans << endl;
  return 0;
}
