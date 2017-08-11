#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 205;
int m, n;
vector<int> G[N];
int vis[N];
int link[N];
bool match(int u)
{
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (vis[v])
            continue;
        vis[v] = 1;
        if (link[v] == -1 || match(link[v])) {
            link[v] = u;
            return true;
        }
    }
    return false;
}
int main()
{
    while (~scanf("%d %d", &n, &m)) {
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            int x, y;
            scanf("%d", &x);
            while (x--) {
                scanf("%d", &y);
                G[i].push_back(y);
            }
        }
        int ans = 0;
        memset(link, -1, sizeof(link));
        for (int i = 1; i <= n; i++) {
            memset(vis, 0, sizeof(vis));
            ans += match(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}