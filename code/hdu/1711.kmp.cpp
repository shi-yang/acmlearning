#include <cstdio>
using namespace std;
int n, m;
int a[1000005], b[10005];
int next[10005];
void get_next()
{
	next[0] = -1;
	int i = 0, j = -1;
	while (i < m) {
		if (j == -1 || b[j] == b[i]) {
			next[++i] = ++j;
		} else {
			j = next[j];
		}
	}
}
int kmp()
{
	int i = 0, j = 0, ans = -1;
	get_next();
	while (i < n) {
		if (j == -1 || a[i] == b[j]) {
			i++, j++;
		} else {
			j = next[j];
		}
		if (j == m) {
			ans = i - m + 1;
			break;
		}
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		for (int i = 0; i < m; i++)
			scanf("%d", b + i);
		printf("%d\n", kmp());
	}
	return 0;
}