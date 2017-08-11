#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 300;
int m, k, c;
int d[N][N];
struct edge {
    int to, cap, rev;
};
vector<edge> G[N];
int iter[N], level[N];
void add_edge(int u, int v, int c)
{
    G[u].push_back((edge){v, c, G[v].size()});
    G[v].push_back((edge){u, 0, G[u].size() - 1});
}
bool bfs(int s, int t)
{
    queue<int> que;
    que.push(s);
    memset(level, 0, sizeof(level));
    level[s] = 1;
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (int i = 0; i < G[now].size(); i++) {
            edge e = G[now][i];
            if (!level[e.to] && e.cap > 0) {
                level[e.to] = level[now] + 1;
                que.push(e.to);
            }
        }
    }
    return level[t];
}
int dfs(int s, int t, int f)
{
    if (s == t)
        return f;
    for (int &i = iter[s]; i < G[s].size(); i++) {
        edge &e = G[s][i];
        if (e.cap > 0 && level[e.to] > level[s]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int maxflow(int s, int t)
{
    int f, res = 0;
    while (bfs(s, t)) {
        memset(iter, 0, sizeof(iter));
        while ((f = dfs(s, t, inf)) > 0)
            res += f;
    }
    return res;
}
int main()
{
    scanf("%d %d %d", &k, &c, &m);
    for (int i = 1; i <= k + c; i++) {
        for (int j = 1; j <= k + c; j++) {
            scanf("%d", &d[i][j]);
            if (!d[i][j])
                d[i][j] = inf;
        }
    }
    for (int x = 1; x <= k + c; x++) {
        for (int y = 1; y <= k + c; y++) {
            for (int z = 1; z <= k + c; z++) {
                d[y][z] = min(d[y][z], d[y][x] + d[x][z]);
            }
        }
    }
    int low = 0, high = inf;
    int s = 0, t = c + k + 1;
    while (low < high) {
        int mid = low + high >> 1;
        for (int i = 0; i < N; i++)
            G[i].clear();
        for (int i = 1; i <= c; i++) {
            add_edge(s, i, 1);
        }
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= c; j++) {
                if (d[j + k][i] <= mid) {
                    add_edge(j, i + c, 1);
                }
            }
        }
        for (int i = 1; i <= k; i++) {
            add_edge(c + i, t, m);
        }
        int res = maxflow(s, t);
        if (res == c) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    printf("%d\n", low);
    return 0;
}