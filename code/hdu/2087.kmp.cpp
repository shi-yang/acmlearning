#include <bits/stdc++.h>
using namespace std;
const int N = 1111;
char s[N], p[N];
int f[N];
void get_next()
{
	int len = strlen(p);
	f[0] = -1;
	int i = 0, j = -1;
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
	int i = 0, j = 0, n = strlen(s), m = strlen(p);
	int ans = 0;
	get_next();
	while (i < n) {
		if (j == -1 || s[i] == p[j]) {
			i++;
			j++;
		} else {
			j = f[j];
		}
		if (j == m) {
			ans++;
			j = 0;
		}
	}
	return ans;
}
int main()
{
	while (~scanf("%s", s) && s[0] != '#') {
		scanf("%s", p);
		printf("%d\n", kmp());
	}
	return 0;
}