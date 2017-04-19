#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int primes[10000];
int bfs(int a, int b)
{
	if (a == b)
		return 0;
	int step[10000] = {0};
	int vis[10000] = {0};
	vis[a] = 1;
	queue<int> que;
	que.push(a);
	while (que.size()) {
		int now = que.front();
		que.pop();
		char tmp[5];
		for (int i = 0; i < 4; i++) {
			sprintf(tmp, "%d", now);
			for (int j = 0; j <= 9; j++) {
				if (!i && !j)
					continue;
				tmp[i] = j + '0';
				int v;
				sscanf(tmp, "%d", &v);
				if (v == b)
					return step[now] + 1;
				if (primes[v] && !vis[v]) {
					vis[v] = 1;
					que.push(v);
					step[v] = step[now] + 1;
				}
			}
		}
	}
	return -1;
}
int main()
{
	memset(primes, -1, sizeof(primes));
	for (int i = 2; i <= 10000; i++) {
		if (primes[i])
			for (int j = i * i; j <= 10000; j += i)
				primes[j] = 0;
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int ans = bfs(a, b);
		if (ans != -1)
			printf("%d\n", ans);
		else
			printf("Impossible\n", ans);
	}	
	return 0;
}
