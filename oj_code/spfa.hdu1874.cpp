#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
vector<pair<int, int> >e[maxn];
int n, m;
int d[maxn], inq[maxn];
int main()
{
  while (cin >> n >> m) {
    for (int i = 0; i < maxn; i++)
      e[i].clear();
    for (int i = 0; i < maxn; i++)
      inq[i] = 0;
    for (int i = 0; i < maxn; i++)
      d[1] = 1e9;
    for (int i = 0; i < n; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      e[x].push_back(make_pair(y, z));
      e[y].push_back(make_pair(x, z));
    }
    int s, t;
    cin >> s >> t;
    queue<int> que;
    que.push(s), d[s] = 0, inq[s] = 1;
    while (!que.empty()) {
      int q = que.front();
      que.pop();
      inq[q] = 0;
      for (int i = 0; i < e[q].size(); i++) {
        int v = e[q][i].first;
        if (d[v] > d[q] + e[q][i].second) {
          d[v] = d[q] + e[q][i].second;
          if (inq[v] == 1)
            continue;
          inq[v] = 0;
          que.push(v);
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
