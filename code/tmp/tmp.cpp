#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cstdio>
#define maxn 10005
#define maxx 20005
using namespace std;
int n, m;
struct edge {
 int u, v, w;
 bool operator <(const edge &oth)const {
  return w>oth.w;
 }
}ed[maxx];
int par[maxn];
void init(int n) {
 int i;
 par[0] = 0;
 for (i = 1; i <= n; i++) {
  par[i] = i;
 }
}
int findset(int a) {
 if (par[a] == a)return a;
 else return par[a] = findset(par[a]);
 //return par[a] == a ? a : par[a] = findset(par[a]);
}
void unite(int x, int y) {
 x = findset(x);
 y = findset(y);
 if (x != y) par[x] = y;
}
int kcruskal() {
 init(n);
 int res = 0;
 int i;
 sort(ed + 1, ed + m + 1);
 for (i = 1; i <= m; i++) {
  int u = ed[i].u;
  int v = ed[i].v;
  if (findset(u) != findset(v)) {
   unite(u, v);
   res += ed[i].w;
  }
 }
 return res;
}
int main()
{
 cin >> n >> m;
 int i, u, v, w,flag=1;
 for (i = 1; i <= m; i++) {
  cin >> u >> v >> w;
  ed[i].u = u;
  ed[i].v = v;
  ed[i].w = w;
 }
 int t = kcruskal();
 for (int j = 2; j <= n; j++) {
  if (findset(j) != findset(1))
    flag = 0;
 }
 if (flag)
  cout << t<< endl;
 else cout << -1 << endl;
 return 0;
}
