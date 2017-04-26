#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int a[maxn];
int main()
{
    freopen("data.in", "r", stdin);
    int n, m;
    cin >> n;
    int ans, k = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == i)
        m++;
    }
    for (int i = 0; i < n && !k; i++) {
      if (a[i] != i && a[a[i]] == i) {
        k = 1;
      }
    }
    ans = (m == n) ? n : (m + k + 1);
    cout << ans << endl;
    return 0;
}
