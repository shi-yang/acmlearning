//Dinic  O(|E|*|V| ^ 2)
struct edge {
    int to, cap, rev;
};
vector<edge> G[N];
int level[N];
int iter[N];
void add_edge(int from, int to, int cap)
{
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size() - 1});
}
bool bfs(int s, int t)
{
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (que.size()) {
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
    return level[t] != -1;
}
int dfs(int v, int t, int f)
{
    if (v == t)
        return f;
    for (int &i = iter[v]; i < G[v].size(); i++) {
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

// Edmonds-Karp
struct edge {
    int from, to, cap, flow;
    edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
vector<edge> edges;
vector<int> G[N];
int a[N];
int p[N];
void add_edge(int u, int v, int c)
{
    edges.push_back(edge(u, v, c, 0));
    edges.push_back(edge(v, u, 0, 0));
    int d = edges.size();
    G[u].push_back(d - 2);
    G[v].push_back(d - 1);
}
int maxflow(int s, int t)
{
    int flow = 0;
    for (;;) {
        memset(a, 0, sizeof(a));
        queue<int> que;
        a[s] = inf;
        que.push(s);
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            for (int i = 0; i < G[now].size(); i++) {
                edge &e = edges[G[now][i]];
                if (e.cap > e.flow && !a[e.to]) {
                    p[e.to] = G[now][i];
                    a[e.to] = min(a[now], e.cap - e.flow);
                    que.push(e.to);
                }
            }
            if (a[t])
                break;
        }
        if (!a[t])
            break;
        for (int i = t; i != s; i = edges[p[i]].from) {
            edges[p[i]].flow += a[t];
            edges[p[i] ^ 1].flow -= a[t];
        }
        flow += a[t];
    }
    return flow;
}

// ISAP
struct Edge {
    int from, to, cap, flow;
    Edge() {}
    Edge(int from, int to, int cap, int flow): from(from), to(to), cap(cap), flow(flow) {}
};

struct ISAP {
    int p[N], num[N], cur[N], d[N];
    int t, s, n, m;
    bool vis[N];

    vector<int> G[N];
    vector<Edge> edges;

    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            G[i].clear();
            d[i] = INF;
        }
        edges.clear();
    }

    void AddEdge(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS() {
        memset(vis, 0, sizeof(vis));

        queue<int> Q;
        d[t] = 0;
        vis[t] = 1;
        Q.push(t);

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            for (int i = 0; i < G[u].size(); i++) {
                Edge &e = edges[G[u][i] ^ 1];
                if (!vis[e.from] && e.cap > e.flow) {
                    vis[e.from] = true;
                    d[e.from] = d[u] + 1;
                    Q.push(e.from);
                }
            }
        }
        return vis[s];
    }

    int Augment() {
        int u = t, flow = INF;
        while (u != s) {
            Edge &e = edges[p[u]];
            flow = min(flow, e.cap - e.flow);
            u = edges[p[u]].from;
        }

        u = t;
        while (u != s) {
            edges[p[u]].flow += flow;
            edges[p[u] ^ 1].flow -= flow;
            u = edges[p[u]].from;
        }
        return flow;
    }

    int Maxflow(int s, int t) {
        this->s = s; this->t = t;
        int flow = 0;
        BFS();
        if (d[s] >= n)
            return 0;

        memset(num, 0, sizeof(num));
        memset(cur, 0, sizeof(cur));
        for (int i = 0; i < n; i++)
            if (d[i] < INF)
                num[d[i]]++;
        int u = s;

        while (d[s] < n) {
            if (u == t) {
                flow += Augment();
                u = s;
            }
            bool ok = false;
            for (int i = cur[u]; i < G[u].size(); i++) {
                Edge &e = edges[G[u][i]];
                if (e.cap > e.flow && d[u] == d[e.to] + 1) {
                    ok = true;
                    p[e.to] = G[u][i];
                    cur[u] = i;
                    u = e.to;
                    break;
                }
            }

            if (!ok) {
                int Min = n - 1;
                for (int i = 0; i < G[u].size(); i++) {
                    Edge &e = edges[G[u][i]];
                    if (e.cap > e.flow)
                        Min = min(Min, d[e.to]);
                }
                if (--num[d[u]] == 0)
                    break;
                num[d[u] = Min + 1]++;
                cur[u] = 0;
                if (u != s)
                    u = edges[p[u]].from;
            }
        }
        return flow;
    }
};


// KM O(n * n * n)
const int N = 505;
const int inf = 0x3f3f3f3f;
int w[N][N];
int n;
int lx[N], ly[N];
int visx[N], visy[N], slack[N];
int linky[N];
bool match(int x)
{
    visx[x] = 1;
    for (int v = 1; v <= n; v++) {
        if (visy[v])
            continue;
        if (lx[x] + ly[v] - w[x][v] == 0) {
            visy[v] = 1;
            if (linky[v] == -1 || match(linky[v])) {
                linky[v] = x;
                return true;
            }
        } else {
            slack[v] = min(slack[v], lx[x] + ly[v] - w[x][v]);
        }
    }
    return false;
}
int km()
{
    memset(ly, 0, sizeof(ly));
    memset(linky, -1, sizeof(linky));
    for (int i = 1; i <= n; i++) {
        lx[i] = -inf;
        for (int j = 1; j <= n; j++) {
            lx[i] = max(lx[i], w[i][j]);
        }
    }
    for (int x = 1; x <= n; x++) {
        memset(slack, inf, sizeof(slack));
        for (;;) {
            memset(visx, 0, sizeof(visx));
            memset(visy, 0, sizeof(visy));
            if (match(x))
                break;
            int d = inf;
            for (int i = 1; i <= n; i++) {
                if (!visy[i])
                    d = min(d, slack[i]);
            }
            for (int i = 1; i <= n; i++) {
                if (visx[i])
                    lx[i] -= d;
                if (visy[i])
                    ly[i] += d;
                else
                    slack[i] -= d;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += lx[i] + ly[i];
    }
    return res;
}
