#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
map<int, int> mp;
queue<int> que[N];
queue<int> rec;
int main()
{
	int t;
	int cas = 1;
	while (~scanf("%d", &t) && t) {
		printf("Scenario #%d\n", cas++);
		while (!rec.empty())
			rec.pop();
		for (int i = 1; i <= t; i++) {
			while (!que[i].empty())
				que[i].pop();
			int x, y;
			scanf("%d", &x);
			for (int j = 0; j < x; j++) {
				scanf("%d", &y);
				mp[y] = i;
			}
		}
		char str[20];
		while (~scanf("%s", str) && str[0] != 'S') {
			if (str[0] == 'E') {
				int x;
				scanf("%d", &x);
				if (que[mp[x]].empty()) {
					rec.push(mp[x]);
				}
				que[mp[x]].push(x);
			} else {
				int tmp = rec.front();
				printf("%d\n", que[tmp].front());
				que[tmp].pop();
				if (que[tmp].empty()) {
					rec.pop();
				}
			}
		}
		putchar('\n');
	}
	return 0;
}