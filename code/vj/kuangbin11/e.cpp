#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 5000;
int n, m, k;
int path[N];
int nk[55][55], mk[55][55];
int needk[55], hask[55];
int a[N];
int dis[N];
int inq[N];
struct edge {
    int to, flow, cap, cost, next;
} e[N];
int head[N];
int cnt;
void add_edge(int from, int to, int cap, int cost)
{
    e[cnt].to = to, e[cnt].cap = cap, e[cnt].flow = 0, e[cnt].cost = cost, e[cnt].next = head[from], head[from] = cnt++;
    e[cnt].to = from, e[cnt].cap = 0, e[cnt].flow = 0, e[cnt].cost = -cost, e[cnt].next = head[to], head[to] = cnt++;
}
int mcmf(int s, int t, int &cost)
{
    int flow = 0;
    for (;;) {
        memset(a, 0, sizeof(a));
        memset(dis, inf, sizeof(dis));
        memset(inq, 0, sizeof(inq));
        dis[s] = 0;
        a[s] = inf;
        stack<int> que;
        que.push(s);
        while (!que.empty()) {
            int now = que.top();
            que.pop();
            inq[now] = 0;
            for (int u = head[now]; u != -1; u = e[u].next) {
                edge es = e[u];
                if (dis[es.to] > dis[now] + es.cost && es.cap > es.flow) {
                    dis[es.to] = dis[now] + es.cost;
                    path[es.to] = u;
                    a[es.to] = min(a[now], es.cap - es.flow);
                    if (inq[es.to])
                        continue;
                    inq[es.to] = 1;
                    que.push(es.to);
                }
            }
        }
        if (dis[t] == inf)
            break;
        for (int i = t; i != s; i = e[path[i] ^ 1].to) {
            e[path[i]].flow += a[t];
            e[path[i] ^ 1].flow -= a[t];
        }
        cost += a[t] * dis[t];
        flow += a[t];
    }
    return flow;
}
void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
}
int main()
{
    while (~scanf("%d %d %d", &n, &m, &k) && (n + m + k)) {
        int s = 0, t = n * k + m * k + 5;
        memset(hask, 0, sizeof(hask));
        memset(needk, 0, sizeof(needk));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < k; j++) {
                scanf("%d", &nk[i][j]);
                needk[j] += nk[i][j];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < k; j++) {
                scanf("%d", &mk[i][j]);
                hask[j] += mk[i][j];
            }
        }
        bool ok = 1;
        int ans = 0;
        for (int d = 0; d < k; d++) {
            init();
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    int x;
                    scanf("%d", &x);
                    add_edge(i, n + j, inf, x);
                }
            }
            if (hask[d] < needk[d]) {
                ok = 0;
            }
            if (!ok)
                continue;
            for (int i = 1; i <= n; i++) {
                add_edge(s, i, nk[i][d], 0);
            }
            for (int i = 1; i <= m; i++) {
                add_edge(n + i, t, mk[i][d], 0);
            }
            int cost = 0;
            mcmf(s, t, cost);
            ans += cost;
        }
        printf("%d\n", ok ? ans : -1);
    }
    return 0;
}
