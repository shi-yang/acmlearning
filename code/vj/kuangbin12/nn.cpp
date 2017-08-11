#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1005;
int a[N], g[N];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	int ans = 0;
	memset(g, INF, sizeof(g));
	for (int i = 0; i < n; i++) {
		int k = lower_bound(g, g + n, a[i]) - g;
		g[k] = a[i];
		ans = max(ans, k + 1);
	}
	printf("%d\n", ans);
	return 0;
}