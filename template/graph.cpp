

struct edge {
  int to, cap, rev;
};
vector<edge> G[maxn];
int level[maxn];
int iter[maxn];
void add_edge(int from, int to, int cap)
{
  G[from].push_back((edge){to, cap, G[to].size()});
  G[to].push_back((edge){to, 0, G[from].size() - 1});
}
void bfs(int s, int t)
{
  memset(level, -1, sizeof(level));
  queue<int> que;
  level[s] = 0;
  que.push(s);
  while (!que.size()) {
    int v = que.front();
    que.pop();
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (e.cap > 0 && level[e.to] < 0) {
        level[e.to] = level[v] + 1;
        que.push(e.to);
      }
    }
  }
  if (level[t] == -1)
    return false;
  return true;
}
int dfs(int v, int t, int f)
{
  if (v == t)
    return f;
  for (int i = iter[v]; i < G[v].size(); i++) {
    edge &e = G[v][i];
    if (e.cap > 0 && level[v] < level[e.to]) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
}
int max_flow(int s, int t)
{
  int flow = 0;
  while (bfs(s, t)) {
    memset(iter, 0, sizeof(iter));
    int f;
    while ((f = dfs(s, t, inf)) > 0)
      flow += f;
  }
  return flow;
}