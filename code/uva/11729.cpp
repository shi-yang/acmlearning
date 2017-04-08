#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn], b[maxn];
int main()
{
  int n;
  int kase = 1;
  while (cin >> n && n) {
    pair<int, int> pi[maxn];
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      pi[i] = make_pair(y, x);
    }
    int ans = 0;
    int tmp = 0;
    sort(pi, pi + n);
    for (int i = 0; i < n; i++) {
      tmp += pi[i].first;
      ans = max(ans, tmp + pi[i].second);
    }
    printf("Case %d: %d\n", kase++, ans);
  }
  return 0;
}
