#include <iostream>
using namespace std;
const int maxn = 105;
char map[maxn][maxn];
int n, m;
void dfs(int x, int y)
{
	map[x][y] = '.';
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int nx = x + i, ny = y + j;
			if (map[nx][ny] == 'W' && 0 <= nx && nx < n && 0 <= ny && ny < m) {
				dfs(nx, ny);
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if (map[i][j] == 'W') {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
