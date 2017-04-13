最短路算法
=========
任意两点间的最短路可用 floyd ，但是用这个算法得考虑时间复杂度，也可将 dijkstra、spfa 改成任意两点间的最短路。将距离数组改成二维就好。

# 应用

- 单源最短路
- 多源最短路
- 传递闭包
- 判断正权、负权回路
- 求图中增广路的最大、最小值

# dijkstra
```c++
int d[maxn];
vector<pair<int, int> > e[maxn];

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
```

# SPFA
```c++
vector<pair<int, int> > E[maxn];
int n, m;
int d[maxn], inq[maxn];

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
```

# Floyd
```c++
for (int k = 1; k <= n; k++) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      // 闭包 mp[i][j] |= mp[i][k] & mp[k][j];
      if (mp[i][j] > mp[i][k] + mp[k][j])
        mp[i][j] = mp[i][k] + mp[k][j];
    }
  }
}
```
