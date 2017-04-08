#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2800;
const int inf = 1e9;
int n, m, w;
struct edge {
    int to, time;
};
vector<edge> G[maxn];
int inq[maxn];
int d[maxn];
bool spfa()
{
    memset(inq, 0, sizeof(inq));
    int cnt[maxn];
    for (int i = 1; i <= n; i++)
        d[i] = inf, cnt[i] = 0;
    d[1] = 0;
    inq[1] = 1;
    queue<int> que;
    que.push(1);
    while (que.size()) {
        int now = que.front();
        que.pop();
        inq[now] = 0;
        for (int i = 0; i < G[now].size(); i++) {
            int v = G[now][i].to;
            if (d[v] > d[now] + G[now][i].time) {
                d[v] = d[now] + G[now][i].time;
                if (inq[v])
                    continue;
                inq[v] = 1;
                cnt[v]++;
                if (cnt[v] > n)
                    return true;
                que.push(v);
            }
        }
    }
    return false;
}
int main()
{
    int f;
    scanf("%d", &f);
    while (f--) {
        scanf("%d %d %d", &n, &m, &w);
        for (int i = 1; i <= n; i++)
            G[i].clear();
        int x, y, z;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &z);
            G[x].push_back((edge){y, z});
            G[y].push_back((edge){x, z});
        }
        for (int i = 0; i < w; i++) {
            scanf("%d %d %d", &x, &y, &z);
            G[x].push_back((edge){y, -z});
        }
        if (spfa()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
