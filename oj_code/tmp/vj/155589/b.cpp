#include <bits/stdc++.h>
using namespace std;
int c[5];
int a[1005];
int b[1005];
int main()
{
  for (int i = 0; i < 4; i++)
    cin >> c[i];
  int n, m;
  cin >> n >> m;
  int suma = 0, sumb = 0;
  int cnta0 = 0, cntb0 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i], suma += a[i];
    if (!a[i])
      cnta0++;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i], sumb += b[i];
    if (!b[i])
      cntb0++;
  }
  int ans[10];
  cout << ans << endl;   
  return 0;
}