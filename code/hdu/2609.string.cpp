#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
char str[N];
int pos(char *s, int len)
{
	int i = 0, j = 1, k = 0;
	while (i < len && j < len && k < len) {
		if (s[(i + k) % len] == s[(j + k) % len]) {
			k++;
		} else {
			if (s[(i + k) % len] < s[(j + k) % len])
				i += k + 1;
			else
				j += k + 1;
			if (i == j)
				j++;
			k = 0;
		}
	}
	return min(i, j);
}
set<string> s;
int main()
{
	int n;
	while (~scanf("%d", &n)) {
		s.clear();
		for (int i = 0; i < n; i++) {
			scanf("%s", str);
			int len = strlen(str);
			int p = pos(str, len);
			string tmp;
			for (int i = 0; i < len; i++) {
				tmp += str[(i + p) % len];
			}
			s.insert(tmp);
		}
		printf("%d\n", s.size());
	}
	return 0;
}