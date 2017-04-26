#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct edge {
  int to, cost;
  edge (int tt, int cc) : to(tt), cost(cc) {}
  bool operator< (const edge &a) const {
    return a.cost < cost;
  }
};
int m, n;
int vis[15000];
vector<edge> e[15000];
void prim()
{
  priority_queue<edge> que;
  for (int i = 0; i < e[1].size(); i++)
    que.push(e[1][i]);
  int ans = 0;
  vis[1] = 1;
  while (que.size()) {
    edge now = que.top();
    que.pop();
    if (vis[now.to])
      continue;
    vis[now.to] = 1;
    for (int i = 0; i < e[now.to].size(); i++)
      que.push(e[now.to][i]);
    ans += now.cost;
  }
  cout << ans << endl;
}
int main()
{
  while (cin >> m >> n) {
    for (int i = 0; i < 15000; i++) {
      e[i].clear();
      vis[i] = 0;
    }  
    for (int i = 0; i < n; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      e[a].push_back(edge(b, c));
      e[b].push_back(edge(a, c));
    }
    prim();
  }
  return 0;  
}