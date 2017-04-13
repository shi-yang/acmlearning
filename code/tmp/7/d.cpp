#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, mv;
int sx, sy;
char mp[105][105];
int vis[105][105];
struct edge {
    int x, y;
    edge(int x, int y) : x(x), y(y) {}
};
bool check(int x, int y)
{
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (mp[nx][ny] == 'E') {
                return true;
            }
        }
    }
    return false;
}
void bfs()
{
    memset(vis, 0, sizeof(vis));
    queue<edge> que;
    que.push(edge(sx, sy));
    vis[sx][sy] = mv;
    while (que.size()) {
        edge now = que.front();
        que.pop();
				int dt = vis[now.x][now.y];
        if (dt <= 0) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i], ny = now.y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                char t = mp[nx][ny];
                if (t == 'E') {
                    continue;
                }
                if (check(nx, ny)) {
                    if (t != 'P' && t != '#' && t != 'Y')
                        mp[nx][ny] = '*';
                    continue;
                }
                if ((t == '.' || t == '*' || t == 'P') && vis[nx][ny] <= dt - 1) {
                    if (vis[nx][ny] < dt - 1) {
                        que.push(edge(nx, ny));
                        vis[nx][ny] = dt - 1;
                    }
										if (t != 'P')
                    	mp[nx][ny] = '*';
                } else if (t == 'T' && dt >= 2) {
                    if (vis[nx][ny] < dt - 2) {
                        que.push(edge(nx, ny));
                        vis[nx][ny] = dt - 2;
                    }
                    mp[nx][ny] = '*';
                } else if (t == 'R' && dt >= 3) {
                    if (vis[nx][ny] < dt - 3) {
                        que.push(edge(nx, ny));
                        vis[nx][ny] = dt - 3;
                    }
                    mp[nx][ny] = '*';
                } else if (t == '#') {
                    ;
                }
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &mv);
        for (int i = 0; i < n; i++) {
            scanf("%s", mp[i]);
            for (int j = 0; j < m; j++) {
                if (mp[i][j] == 'Y') {
                    sx = i, sy = j;
                }
            }
        }
        bfs();
        for (int i = 0; i < n; i++) {
            printf("%s\n", mp[i]);
        }
        printf("\n");
    }
    return 0;
}
