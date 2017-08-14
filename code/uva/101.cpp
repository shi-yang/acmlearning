#include <bits/stdc++.h>
using namespace std;
stack<int> s[30];
int block[30];
void clear(int x)
{
	while (s[block[x]].top() != x) {
		int now = s[block[x]].top();
		s[block[x]].pop();
		block[now] = now;
		s[now].push(now);
	}
}
void pile(int a, int b)
{
	queue<int> que;
	que.push(a);
	while (s[block[a]].top() != a) {
		que.push(s[block[a]].top());
		s[block[a]].pop();
	}
	s[block[a]].pop();
	while (!que.empty()) {
		s[block[b]].push(que.front());
		block[que.front()] = block[b];
		que.pop();
	}
	block[a] = block[b];
}
void move(int a, int b)
{
	s[block[a]].pop();
	block[a] = block[b];
	s[block[b]].push(a);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		block[i] = i;
		s[i].push(i);
	}
	char str[10];
	while (~scanf("%s", str) && str[0] != 'q') {
		int a, b;
		char op[10];
		scanf("%d %s %d", &a, op, &b);
		if (a == b || block[a] == block[b])
			continue;
		if (str[0] == 'm' && op[1] == 'n') {
			clear(a);
			clear(b);
			move(a, b);
		} else if (str[0] == 'm' && op[1] == 'v') {
			clear(a);
			move(a, b);
		} else if (str[0] == 'p' && op[1] == 'n') {
			clear(b);
			pile(a, b);
		} else {
			pile(a, b);
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d:", i);
		stack<int> tmp;
		while (!s[i].empty()) {
			tmp.push(s[i].top());
			s[i].pop();
		}
		while (!tmp.empty()) {
			printf(" %d", tmp.top());
			tmp.pop();
		}
		printf("\n");
	}
	return 0;
}