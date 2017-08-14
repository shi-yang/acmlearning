#include <bits/stdc++.h>
using namespace std;
char s[1000005], p[10005];
int f[10005];
void get_next()
{
	int i = 0, j = -1, len = strlen(p);
	f[0] = -1;
	while (i < len) {
		if (j == -1 || p[i] == p[j]) {
			f[++i] = ++j;
		} else {
			j = f[j];
		}
	}
}
int kmp()
{
	int i = 0, j = 0, len_s = strlen(s), len_p = strlen(p);
	int ans = 0;
	get_next();
	while (i < len_s) {
		if (j == -1 || s[i] == p[j]) {
			i++, j++;
		} else {
			j = f[j];
		}
		if (j == len_p) {
			ans++;
		}
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s %s", p, s);
		printf("%d\n", kmp());
	}
	return 0;
}