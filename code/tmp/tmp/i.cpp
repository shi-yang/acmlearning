#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const int inf = 1e9;
int n;
struct edge {
  int to, cost;
  edge() {}
  edge(int to, int cost) : to(to), cost(cost) {}
};
vector<edge> G[maxn];
int inq[maxn];
int d[maxn];
int main()
{
  int t;
  scanf("%d", &t);
  for (int cas = 1; cas <= t; cas++) {
    map<string, int> mp;
    scanf("%d", &n);
    for (int i = 0; i < maxn; i++)
      G[i].clear(), d[i] = inf;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int k;
      char ss[5];
      scanf("%s %d", ss, &k);
      string str[11];
      for (int j = 0; j < k; j++) {
        cin >> str[j];
        if (!mp[str[j]]) {
          mp[str[j]] = ++cnt;
        }
      }
      for (int jj = 0; jj < k; jj++) {
        for (int qq = jj + 1; qq < k; qq++) {
          if (ss[0] == 'A') {
            G[mp[str[jj]]].push_back(edge(mp[str[qq]], 2));
            G[mp[str[qq]]].push_back(edge(mp[str[jj]], 2));
          } else {
            G[mp[str[jj]]].push_back(edge(mp[str[qq]], 0));
            G[mp[str[qq]]].push_back(edge(mp[str[jj]], 0));
          }
        }
      }
    }
    string st, et;
    cin >> st >> et;
    int ss = mp[st], tt = mp[et];
    memset(inq, 0, sizeof(inq));
    inq[ss] = 1;
    d[ss] = 0;
    queue<int> que;
    que.push(ss);
    while (que.size()) {
      int now = que.front();
      inq[now] = 1;
      que.pop();
      for (int i = 0; i < G[now].size(); i++) {
        int v = G[now][i].to;
        if (d[v] > d[now] + G[now][i].cost) {
          d[v] = d[now] + G[now][i].cost;
          if (inq[v])
            continue;
          inq[v] = 1;
          que.push(v);
        }
      }
    }
    printf("Case #%d: %d\n", cas, d[tt]);
  }
  return 0;
}
