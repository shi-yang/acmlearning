#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Trie {
	int count;
	Trie * child[26];
	Trie() {
		count = 0;
		memset(child, 0, sizeof(child));
	}
};
Trie * head = new Trie();
void insert(char * s)
{
	Trie * p = head;
	for (int i = 0; s[i]; i++) {
		int idx = s[i] - 'a';
		if (p->child[idx] == NULL) {
			p->child[idx] = new Trie();
		}
		p = p->child[idx];
		p->count++;
	}
}

int search(char * s)
{
	Trie * p = head;
	for (int i = 0; s[i]; i++) {
		int idx = s[i] - 'a';
		if (p->child[idx] == NULL)
			return 0;
		p = p->child[idx];
	}
	return p->count;	
}
int main()
{
     char s[11];
     int i = 0;
     for (;;) {
     	while ((s[i] = getchar()) != '\n')
     		i++;
     	s[i] = '\0';
     	insert(s);
     	i = 0;
     	if ((s[i] = getchar()) == '\n')
     		break;
     	i++;
     }
     while(~scanf("%s", s))
         printf("%d\n", search(s));
	return 0;
}