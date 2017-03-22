#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10005;
int f[maxn];
struct edge {
  int a, b, c;
} e[maxn];
bool cmp(edge a, edge b)
{
  return a.c < b.c;
}
int root(int x)
{
  return x == f[x] ? x : f[x] = root(f[x]);
}
int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < maxn; i++) {
    f[i] = i;
  }
  for (int i = 0; i < m; i++) {
    cin >> e[i].a >> e[i].b >> e[i].c;
  }
  sort(e, e + m, cmp);
  int ans;
  for (int i = 0; i < m; i++) {
    if (root(e[i].a) != root(e[i].b)) {
      f[root(e[i].a)] = root(e[i].b);
      ans = e[i].c;
    }
  }
  cout << ans << endl;
  return 0;
}
