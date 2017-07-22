#include <bits/stdc++.h>

using namespace std;

const int N = 60000;

struct Node {
	string s;
	int left, right, hash;
	bool operator < (const Node & a) const {
		if (hash != a.hash)
			return hash < a.hash;
		if (left != a.left)
			return left < a.left;
		return right < a.right;
	}
} node[N];
map<Node, int> dict;
int cnt;
char *p;
char str[N * 6];
int done[N];

int parse()
{
	int id = cnt++;
	Node &u = node[id];
	u.left = u.right = -1;
	u.hash = 0;
	u.s = "";
	while (isalpha(*p)) {
		u.s.push_back(*p);
		u.hash = u.hash * 27 + *p - 'a' + 1;
		p++;
	}
	if (*p == '(') {
		p++;
		u.left = parse(); p++;
		u.right = parse(); p++;
	}
	if (dict.count(u)) {
		cnt--;
		id--;
		return dict[u];
	}
	return dict[u] = id;
}

void print(int u, int v)
{
	if (done[u] == v) {
		printf("%d", u + 1);
	} else {
		done[u] = v;
		printf("%s", node[u].s.c_str());
		if (node[u].left != -1) {
			putchar('(');
			print(node[u].left, v);
			putchar(',');
			print(node[u].right, v);
			putchar(')');
		}
	}
}
int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		dict.clear();
		cnt = 0;
		scanf("%s", str);
		p = str;
		print(parse(), tt);
		puts("");
	}
	return 0;
}
