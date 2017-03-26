#include <bits/stdc++.h>
using namespace std;
const int maxstate = 1e7;
int goal[9];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct edge {
	int * a;
	int d;
} st[maxstate];
set<int> vis;
int  isvis(int s)
{
	int v = 0;
	for (int i = 0; i < 9; i++)
		v = v * 10 + st[s][i];
	if (vis.count(v))
		return 0;
	vis.insert(v);
	return 1;
}
int bfs()
{
	vis.clear();
	queue<edge> que;
	que.push(edge{st[0].a, 0});
	int cnt = 0;
	while (que.size()) {
		st[++cnt] = que.front();
		edge now = st[cnt];
		que.pop();
		if (memcmp(goal, now.a, sizeof(now.a)) == 0)
			return now.d;
		int pos = 0;
		while (!now.a[pos++])
			;
		int x = pos / 3, y = pos % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + d[i], ny = y + d[i];
			int npos = nx * 3 + ny;
			if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
				int * tmp = now.a;
				
				d[rear] = d[front] + 1;
				if (isvis(rear))
					rear++;
			}
		}
	}
}

int main()
{
	int a[9];
	for (int i = 0; i < 9; i++)
		cin >> a[i];
	st[0].a = a;
	for (int i = 0; i < 8; i++)
		goal[i] = i + 1;
	goal[8] = 0;
	int ans = bfs();
	return 0;
}
