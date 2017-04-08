#include <bits/stdc++.h>
using namespace std;
int n;
char s[209999];
queue<int> p[2];
int main() {
	scanf("%d%s", &n, s);
	for(int i = 0; i < n; i++)
		p[s[i] == 'D'].push(i);
	while(!p[0].empty() && !p[1].empty()) {
		bool b = p[1].front() < p[0].front();
		p[!b].pop();
		p[b].push(p[b].front() + n);
		p[b].pop();
	}
	if (p[0].empty())
		printf("D\n");
	else
		printf("R\n");
	return 0;
}
