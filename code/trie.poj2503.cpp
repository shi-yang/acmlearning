#include <cstdio>
#include <cstring>

struct Trie {
	int ok;
	char s[15];
	Trie * child[26];
	Trie () {
		memset(child, 0, sizeof(child));
		ok = 0;
	}
};
Trie * head = new Trie();

void insert(char *s, char *t)
{
	Trie * p = head;
	for (int i = 0; s[i]; i++) {
		int idx = s[i] - 'a';
		if (p->child[idx] == NULL)
			p->child[idx] = new Trie();
		p = p->child[idx];
	}
	p->ok = 1;
	strcpy(p->s, t);
}
void search(char *s)
{
	Trie * p = head;
	for (int i = 0; s[i]; i++) {
		int idx = s[i] - 'a';
		if (p->child[idx] == NULL) {
			printf("eh\n");
			return;
		}
		p = p->child[idx];
	}
	if (p->ok) {
		printf("%s\n", p->s);
	} else {
		printf("eh\n");
	}
}
int main()
{
     char s[15], t[15];
     int i = 0;
     for (;;) {
     	while ((s[i] = getchar()) != ' ')
     		i++;
     	s[i] = '\0';
     	i = 0;
     	while ((t[i] = getchar()) != '\n')
     		i++;
     	t[i] = '\0';
     	insert(t, s);
     	i = 0;
     	if ((s[i++] = getchar()) == '\n')
     		break;
     }
     while(~scanf("%s", s)) {
     	search(s);
     }
	return 0;
}