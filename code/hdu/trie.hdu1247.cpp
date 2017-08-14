#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char in[50005][50];
struct Trie {
	int ok;
	Trie * child[26];
	Trie() {
		ok = 0;
		memset(child, 0, sizeof(child));
	}
};
Trie * head = new Trie();
void insert(char *s)
{
	Trie * p = head;
	for (int i = 0; s[i]; i++) {
		int idx = s[i] - 'a';
		if (p->child[idx] == NULL) {
			p->child[idx] = new Trie();
		}
		p = p->child[idx];
	}
	p->ok = 1;
}
bool search(char * s)
{
	Trie * p = head;
	for (int i = 0; s[i]; i++) {
		int idx = s[i] - 'a';
		if (p->child[idx] == NULL)
			return false;
		p = p->child[idx];
	}
	return p->ok;
}
int main()
{
	char s[50];
	int cnt = 0;
	for (cnt = 0; ~scanf("%s", in[cnt]); cnt++) {
		insert(in[cnt]);
	}
	for (int i = 0; i < cnt; i++) {
		int len = strlen(in[i]);
		for (int j = 0; j < len; j++) {
			char x[55], y[55];
			int k;
			for (k = 0; k <= j; k++)
				x[k] = in[i][k];
			x[k] = '\0';
			for (k = j + 1; k < len; k++)
				y[k - j - 1] = in[i][k];
			y[k - j - 1] = '\0';
			if (search(x) && search(y)) {
				printf("%s\n", in[i]);
				break;
			}
		}
	}
	return 0;
}