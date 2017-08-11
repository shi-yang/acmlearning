#include <bits/stdc++.h>
using namespace std;
const int N = (int) 3e5;
char s[N], t[N];
int p[N];
int main()
{
	while (~scanf("%s", s)) {
		int len_s = strlen(s), len_t = 2;
		t[0] = '$';
		t[1] = '#';
		for (int i = 0; i < len_s; i++) {
			t[len_t++] = s[i];
			t[len_t++] = '#';
		}
		t[len_t] = '\0';
		int ans = 0, id = 0, mx = 0;
		for (int i = 1; i < len_t; i++) {
			p[i] = i < mx ? min(p[id + id - i], mx - i) : 1;
			while (t[i - p[i]] == t[i + p[i]])
				p[i]++;
			if (mx < i + p[i]) {
				mx = i + p[i];
				id = i;
			}
			ans = max(ans, p[i] - 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}