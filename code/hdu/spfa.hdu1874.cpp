#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
vector<pair<int, int> > E[maxn];
int n, m;
int d[maxn], inq[maxn];
int main()
{
  while (cin >> n >> m) {
    for (int i = 0; i < maxn; i++) {
      E[i].clear();
      inq[i] = 0;
      d[i] = 1e9;
    }
    for (int i = 0; i < m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      E[x].push_back(make_pair(y, z));
      E[y].push_back(make_pair(x, z));
    }
    int s, t;
    cin >> s >> t;
    queue <int> que;
    que.push(s);
    d[s] = 0, inq[s] = 1;
    while (!que.empty()) {
      int now = que.front();
      que.pop();
      for (int i = 0; i < E[now].size(); i++) {
        int v = E[now][i].first;
        if (d[v] > d[now] + E[now][i].second) {
          d[v] = d[now] + E[now][i].second;
          if (inq[v] == 1)
            continue;
          inq[v] = 1;
          que.push(v);
        }
      }
      inq[now] = 0;
    }
    if (d[t] == 1e9)
      cout << -1 << endl;
    else
      cout << d[t] << endl;
  }
  return 0;
}
