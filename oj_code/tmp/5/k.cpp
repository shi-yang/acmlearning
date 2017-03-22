#include <iostream>
using namespace std;
const int maxn = 505;
char m[maxn][maxn];
int r, c;
int sx, sy;
int ex, ey;
int bfs()
{
	que
}
int main()
{
	while (cin >> r >> c, r + c) {
		for (int i = 0; i < c; i++) {
			cin >> m[i];
			for (int j = 0; j < r; j++) {
				if (m[i][j] == 'X') {
					sx = i, sy = j;
				}
				if (m[i][j] == 'O') {
					ex = i, ey = j;
				}
			}
		}
		bfs();
	}
	return 0;
}
