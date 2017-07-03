#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int N = 105;
const int inf = 0x3f3f3f3f;
struct edge {
  int to, co;
  edge(){}
  edge(int to, int co) : to(to), co(co) {}
};
vector<edge> G[N];
int dis[N];
void dijkstra()
{
  memset(dis, inf, sizeof(dis));
  priority_queue<pair<int, int> > que;
  que.push(make_pair(0, 1));
  dis[1] = 0;
  while (!que.empty()) {
    int now = que.top().second;
    que.pop();
    for (int i = 0; i < G[now].size(); i++) {
      int u = G[now][i].to;
      if (dis[u] > dis[now] + G[now][i].co) {
        dis[u] = dis[now] + G[now][i].co;
        que.push(make_pair(-dis[u], u));
      }
    }
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i - 1; j++) {
      char str[10];
      int x;
      scanf("%s", str);
      if (str[0] != 'x') {
        sscanf(str, "%d", &x);
        G[i].push_back(edge(j, x));
        G[j].push_back(edge(i, x));
      }
    }
  }
  dijkstra();
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dis[i]);
  }
  printf("%d\n", ans);
  return 0;
}
