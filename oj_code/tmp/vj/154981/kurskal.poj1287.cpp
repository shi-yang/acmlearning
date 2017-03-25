#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 55;
int m, n;
struct edge {
  int from, to, cost;
} e[15000];
bool cmp(edge a, edge b)
{
  return a.cost < b.cost;
}
int f[maxn];
int root(int x)
{
  return x == f[x] ? x : f[x] = root(f[x]);
}
int main()
{
  while (cin >> m >> n) {
    for (int i = 1; i <= maxn; i++)
      f[i] = i;
    for (int i = 0; i < n; i++) {             
      cin >> e[i].from >> e[i].to >> e[i].cost;
    }
    sort(e, e + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int a = e[i].from, b = e[i].to;
      if (root(a) == root(b)) {
        continue;
      }
      f[root(a)] = root(b);
      ans += e[i].cost;
    }
    cout << ans << endl;
  }
  return 0;
}