#include <iostream>
#include <algorithm>
using namespace std;
int a[50005];
struct edge {
  int s, v;
}e[50005];
bool cmp(edge a, edge b)
{
  return a.v < b.v;
}
int main()
{
  freopen("in", "r", stdin);
  int l, n, m;
  cin >> l >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  e[0].v = a[0];
  e[0].s = 0;
  for (int i = 1; i < n; i++) {
    e[i].v = a[i] - a[i - 1];
    e[i].s = i;
  }
  e[n + 1].v = l - a[i];
  sort(e, e + n, cmp);
  cout << e[m + 1].v << endl;
  return 0;
}
