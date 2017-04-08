#include <bits/stdc++.h>
using namespace std;
const int maxn = 20005;
int a[maxn], b[maxn];
int main()
{
  int n, m;
  while (cin >> n >> m && (n + m)) {
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < m; i++)
      cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      if (b[i] >= a[cnt]) {
        ans += b[i];
        cnt++;
      }
      if (cnt == n)
        break;
    }
    if (cnt < n)
      cout << "Loowater is doomed!" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
