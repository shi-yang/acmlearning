#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
int d[15][N];
int main()
{
	int n;
	while (~scanf("%d", &n) && n) {
		int time = -1e9;
		for (int i = 0; i < n; i++) {
			int t, x;
			scanf("%d %d", &x, &t);
			d[x][t]++;
			time = max(time, t);
		}
		for (int i = 0; i < time; i++) {
			
		}
	}
	return 0;
}
