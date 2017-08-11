#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int w, h;
char mp[50][50];
int rec[50][50];
vector<int> G[405];
int vis[405];
int match[405];
bool dfs(int u)
{
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (vis[v])
			continue;
		vis[v] = 1;
		if (match[v] == -1 || dfs(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &h, &w);
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			scanf("%s", mp[i]);
			for (int j = 0; j < w; j++) {
				if (mp[i][j] == '*')
					rec[i][j] = cnt++;
			}
		}
		for (int i = 0; i <= cnt; i++)
			G[i].clear();
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (mp[i][j] == '*') {
					for (int k = 0; k < 4; k++) {
						int nx = dx[k] + i, ny = dy[k] + j;
						if (0 <= nx && nx < h && 0 <= ny && ny < w && mp[nx][ny] == '*') {
							int u = rec[i][j], v = rec[nx][ny];
							G[u].push_back(v);
						}
					}
				}
			}
		}
		int tmp = 0;
		memset(match, -1, sizeof(match));
		for (int i = 0; i < cnt; i++) {
			memset(vis, 0, sizeof(vis));
			tmp += dfs(i);
		}
		for (int i = 0; i < cnt; i++) {
			printf("%d -> %d\n", i + 1, match[i] + 1);
		}
		printf("%d\n", cnt - tmp / 2);
	}
	return 0;
}