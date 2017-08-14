#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1005;
int used[maxn];
struct edge {
  int d, s;
} e[maxn];
bool cmp(edge a, edge b)
{
  if (a.s != b.s)
    return a.s > b.s;
  return a.d < b.d;
}
int main()
{
  int t;
  cin >> t;
  while (t--) {
    memset(used, 0, sizeof(used));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> e[i].d;
    }
    for (int i = 0; i < n; i++) {
      cin >> e[i].s;
    }
    sort(e, e + n, cmp);
    int ans = 0, cnt = 1, pos;
    for (int i = 0; i < n; i++) {
      int now = e[i].d + 1;
      while (--now) {
        if (!used[now]) {
          used[now] = 1;
          break;
        }
      }
      if (now == 0) {
        ans += e[i].s;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
