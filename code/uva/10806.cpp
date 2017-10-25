#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 205;
struct edge {
    int from, to, cap, flow, cost;
};
vector<edge> E;
vector<int> G[N];
void add_edge(int u, int v, int c, int w)
{
    E.push_back((edge){u, v, c, 0, w});
    E.push_back((edge){v, u, 0, 0, -w});
    int q = E.size();
    G[u].push_back(q - 2);
    G[v].push_back(q - 1);
}
int a[N], path[N], dis[N], inq[N];
int mcmf(int s, int t, int &cost)
{
    int flow = 0;
    for (;;) {
        memset(a, 0, sizeof(a));
        memset(inq, 0, sizeof(inq));
        memset(dis, inf, sizeof(dis));
        a[s] = inf;
        dis[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            inq[now] = 0;
            for (int i = 0; i < G[now].size(); i++) {
                edge e = E[G[now][i]];
                if (dis[e.to] > dis[now] + e.cost && e.cap > e.flow) {
                    dis[e.to] = dis[now] + e.cost;
                    a[e.to] = min(a[now], e.cap - e.flow);
                    path[e.to] = G[now][i];
                    if (inq[e.to])
                        continue;
                    inq[e.to] = 1;
                    que.push(e.to);
                }
            }
        }
        if (dis[t] == inf)
            break;
        cost += dis[t] * a[t];
        flow += a[t];
        for (int i = t; i != s; i = E[path[i]].from) {
            E[path[i]].flow += a[t];
            E[path[i] ^ 1].flow -= a[t];
        }
    }
    return flow;
}
int main()
{
    int n, m;
    while (~scanf("%d", &n) && n) {
        int s = 0, t = n + 1;
        E.clear();
        for (int i = s; i <= t; i++)
            G[i].clear();
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            add_edge(u, v, 1, c);
            add_edge(v, u, 1, c);
        }
        int cost = 0;
        add_edge(s, 1, 2, 0);
        add_edge(n, t, 2, 0);
        int cnt = mcmf(s, t, cost);
        if (cnt == 2) {
            printf("%d\n", cost);
        } else {
            puts("Back to jail");
        }
    }
    return 0;
}
