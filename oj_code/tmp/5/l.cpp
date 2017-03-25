#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1005;
vector<pair<int, int> > G[maxn];
int p[maxn];
int d[maxn];
int inq[maxn];
int n, m;
int bfs(int c, int s, int t)
{
  inq[s] = 1;
  d[s] = 0;   
  int cur_c;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (int i = 0; i < G[now].size(); i++) {
      if (G[now][i].second > c) {
        continue;
      }
      int v = G[now][i].first;
      if (p[now] < p[v]) {
        cur_c = c;  
      } else {
        cur_c = G[now][i].second;
      } 
      if (d[v] > d[now] + cur_c * G[now][i].second) {
        d[v] = d[now] + cur_c * G[now][i].second;
        if (inq[v] == 1)
          continue;
        inq[v] = 1;
        que.push(v);
      }
    }
    inq[now] = 0;
  }
  return 0;
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++) {      
    cin >> p[i];
  }
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    G[a].push_back(make_pair(b, c));
  }
  int q;
  cin >> q;
  while (q--) {
    for (int i = 0; i < n; i++)
      d[i] = 1e9;
    memset(inq, 0, sizeof(inq));
    int c, s, t;
    cin >> c >> s >> t;
    bfs(c, s, t);
    if (d[t] != 1e9) {
      cout << d[t] << endl;
    } else {
      cout << "impossible" << endl;
    }
  }
  return 0;
}