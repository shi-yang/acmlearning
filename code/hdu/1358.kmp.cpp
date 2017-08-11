#include <bits/stdc++.h>
using namespace std;
const int N = (int) 1e6 + 10;
char s[N];
int nex[N];
int main()
{
	int cas = 1, n;
	while (~scanf("%d", &n) && n) {
		scanf("%s", s);
		int i = 0, j = -1;
		nex[0] = -1;
		while (i < n) {
			if (j == -1 || s[i] == s[j]) {
				nex[++i] = ++j;
			} else {
				j = nex[j];
			}
		}
		printf("Test case #%d\n", cas++);
		for (int i = 0; i <= n; i++) {
			if (nex[i] == -1 || !nex[i])
				continue;
			j = i - nex[i];
			if (i % j == 0)
				printf("%d %d\n", i, i / j);
		}
		printf("\n");
	}
	return 0;
}