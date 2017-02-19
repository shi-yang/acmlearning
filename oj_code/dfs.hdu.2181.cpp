/*
 hdu 2181
 dfs 水题，在这里使用了个二维数组，用来保存当前点可到哪些点，然后利用 DFS 扫就得了
 */
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int ma[25][3];
int vis[25], tmp[25];
int m, cas;
void dfs(int x, int cnt)
{
	vis[x] = 1;
	tmp[cnt] = x;
	if (cnt == 19) {
		for (int i = 0; i < 3; i++) {
			if (ma[x][i] == tmp[0]) {
				printf("%d:  ", ++cas);
				for (int i = 0; i < 20; i++) {
					printf("%d ", tmp[i]);
				}
				printf("%d\n", tmp[0]);
			}
		}
		return ;
	}
	for (int i = 0; i < 3; i++) {
		int t = ma[x][i];
		if (!vis[t]) {
			dfs(t, cnt + 1);
			vis[t] = 0;
		}
	}
}
int main()
{
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	for (int i = 1; i <= 20; i++) {
		scanf("%d%d%d", &ma[i][0], &ma[i][1], &ma[i][2]);
	}
	scanf("%d", &m);
	if (m) {
		memset(vis, 0, sizeof(vis));
		memset(tmp, 0, sizeof(tmp));
		cas = 0;
		dfs(m, 0);
	}
	return 0;
}