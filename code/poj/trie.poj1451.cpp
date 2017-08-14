#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1005;
char in[N][105];
int rec[N][105];
int w[N];
char dict[] = "abcdefghijklmnopqrstuvwxyz";
char tran[] = "22233344455566677778889999";
struct Trie {
	int ok;
	Trie * child[10];
	char str[105];
	int rec;
	Trie() {
		ok = 0;
		rec = 0;
		memset(child, 0, sizeof(child));
	}
};
Trie * head;
void insert(int id)
{
	char *s = in[id];
	Trie * p = head;
	int cnt = 1;
	while (*s) {
		int c = *s++ - 'a';
		int d = tran[c] - '0';
		if (p->child[d] == NULL) {
			p->child[d] = new Trie();
		}
		p = p->child[d];
		if (p->rec < rec[id][cnt - 1]) {
			p->rec = rec[id][cnt - 1];
			for (int i = 0; i < cnt; i++) {
				p->str[i] = in[id][i];
			}
			p->str[cnt] = '\0';
		}
		cnt++;
	}
}
void query(char *s)
{
	Trie * p = head;
	while (*s != '1') {
		int d = *s++ - '0';
		if (p->child[d] == NULL) {
			printf("MANUALLY\n");
			break;
		}
		p = p->child[d];
		printf("%s\n", p->str);
	}
	while (*s++ != '1') {
		printf("MANUALLY\n");
	}
	printf("\n");
}
int main()
{
	int tt;
	scanf("%d", &tt);
	for (int cas = 1; cas <= tt; cas++) {
		head = new Trie();
		int ww;
		scanf("%d", &ww);
		for (int i = 1; i <= ww; i++) {
			scanf("%s %d", in[i], w + i);
			int len = strlen(in[i]);
			for (int j = 0; j < len; j++) {
				rec[i][j] = w[i];
			}
		}
		for (int i = 1; i <= ww; i++) {
            for(int j = 0; in[i][j] && in[i - 1][j]; j++) {
                if(in[i][j] == in[i - 1][j]) {
                    rec[i][j] += rec[i - 1][j];
                } else {
                	break;
                }
            }
		}
		for (int i = 1; i <= ww; i++) {
			insert(i);
		}
		int m;
		scanf("%d", &m);
		printf("Scenario #%d:\n", cas);
		while (m--) {
			char str[105];
			scanf("%s", str);
			query(str);
		}
		putchar('\n');
	}
	return 0;
}