#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int n, m;
int d[maxn];
vector<pair<int, int> > e[maxn];

int main()
{
  while (cin >> n >> m) {
    for (int i = 0; i < maxn; i++) {
      e[i].clear();
      d[i] = 1e9;
    }
    for (int i = 0; i < m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      e[x].push_back(make_pair(y, z));
      e[y].push_back(make_pair(x, z));
    }
    int s, t;
    cin >> s >> t;
    d[s] = 0;
    priority_queue<pair<int, int> > que;
    que.push(make_pair(-d[s], s));
    while (!que.empty()) {
      int now = que.top().second;
      que.pop();
      for (int i = 0; i < e[now].size(); i++) {
        int v = e[now][i].first;
        if (d[v] > d[now] + e[now][i].second) {
          d[v] = d[now] + e[now][i].second;
          que.push(make_pair(-d[v], v));
        }
      }
    }
    if (d[t] == 1e9) {
      cout << -1 << endl;
    } else {
      cout << d[t] << endl;
    }
  }
  return 0;
}
