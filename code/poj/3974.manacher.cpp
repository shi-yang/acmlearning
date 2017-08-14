#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000005;
char s[N];
char t[N << 1];
int pos[N << 1];
int main()
{
	int cas = 1;
	while (~scanf("%s", s) && strcmp(s, "END")) {
		t[0] = '$';
		t[1] = '#';
		int j = strlen(s), len = 2;
		for (int i = 0; i < j; i++) {
			t[len++] = s[i];
			t[len++] = '#';
		}
		t[len] = '\0';
		int mx = 0, id = 0;
		int ans = 0;
		for (int i = 1; i < len; i++) {
			pos[i] = i < mx ? min(pos[id + id - i], mx - i) : 1;
			while (t[i - pos[i]] == t[i + pos[i]])
				pos[i]++;
			if (pos[i] + i > mx) {
				mx = pos[i] + i;
				id = i;
			}
			ans = max(ans, pos[i] - 1);
		}
		printf("Case %d: %d\n", cas++, ans);
	}
	return 0;
}