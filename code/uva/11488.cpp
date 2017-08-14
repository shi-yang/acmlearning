#include <bits/stdc++.h>
using namespace std;
struct Trie {
	Trie * next[3];
	int cnt[3];
	Trie() {
		memset(next, 0, sizeof(next));
		memset(cnt, 0, sizeof(cnt));
	}
} * head;
int ans;
void insert(char *s)
{
	int d = 0;
	Trie * p = head;
	while (*s) {
		int c = *s++ - '0';
		if (p->next[c] == NULL) {
			p->next[c] = new Trie();
		}
		p = p->next[c];
		p->cnt[c]++;
		d++;
		ans = max(ans, d * p->cnt[c]);
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		ans = 0;
		scanf("%d", &n);
		head = new Trie();
		for (int i = 0; i < n; i++) {
			char str[205];
			scanf("%s", str);
			insert(str);
		}
		printf("%d\n", ans);
	}
	return 0;
}