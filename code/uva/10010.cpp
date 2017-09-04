#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};
char mp[N][N];
int m, n;
void search(char *str)
{
	int len = strlen(str);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (tolower(str[0]) != tolower(mp[i][j]))
				continue;
			for (int k = 0; k < 8; k++) {
				int ok = 1;
				for (int q = 0; q < len; q++) {
					int nx = q * dx[k] + i, ny = q * dy[k] + j;
					if (0 <= nx && nx < m && 0 <= ny && ny < n) {
						if (tolower(mp[nx][ny]) != tolower(str[q])) {
							ok = 0;
							break;
						}
					} else {
						ok = 0;
						break;
					}
				}
				if (ok) {
					printf("%d %d\n", i + 1, j + 1);
					return;
				}
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	int flag = 0;
	while (t--) {
		if (flag) {
			printf("\n");
		}
		flag = 1;
		scanf("%d %d", &m, &n);
		for (int i = 0; i < m; i++) {
			scanf("%s", mp[i]);
		}
		int k;
		scanf("%d", &k);
		while (k--) {
			char str[25];
			scanf("%s", str);
			search(str);
		}
	}
	return 0;
}