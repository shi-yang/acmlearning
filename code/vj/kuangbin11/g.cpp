#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 100005;
const int INF = (int) 1e9;
int n, m;
struct island {
	int x, y;
} land[N];
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

ISAP isap;
int s, t;
int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d %d", &n, &m);
		isap.init(n);
		s = 1, t = 1;
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &land[i].x, &land[i].y);
			if (land[s].x > land[i].x) {
				s = i;
			}
			if (land[t].x < land[i].x) {
				t = i;
			}
		}
		for (int i = 0; i < m; i++) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			isap.AddEdge(u, v, c);
			isap.AddEdge(v, u, c);
		}
		printf("%d\n", isap.Maxflow(s, t));
	}
	return 0;
}