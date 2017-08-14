#include <iostream>
#include <cstdio>
#include <cstring>
const int N = 1005;
char in[N][25];
struct Trie {
	int cnt;
	Trie * child[26];
	Trie() {
		memset(child, 0, sizeof(child));
		cnt = 0;
	}
};
Trie * head = new Trie();
void insert(char *s)
{
	Trie * p = head;
	while (*s) {
		int c = *s - 'a';
		if (p->child[c] == NULL) {
			p->child[c] = new Trie();
		}
		p = p->child[c];
		p->cnt++;
		s++;
	}
}
void print(char *s)
{
	Trie * p = head;
	while (*s) {
		putchar(*s);
		int c = *s - 'a';
		p = p->child[c];
		if (p->cnt == 1) {
			break;
		}
		s++;
	}
	putchar('\n');
}
int main()
{
	int n;
	for (n = 0; ~scanf("%s", in[n]); n++) {
		insert(in[n]);
	}
	for (int i = 0; i < n; i++) {
		printf("%s ", in[i]);
		print(in[i]);
	}
	return 0;
}