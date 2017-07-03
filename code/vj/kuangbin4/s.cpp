#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int N = 1005;
const int M = 20005;
const int inf = 0x3f3f3f3f;
vector<pair<int, int> > G[N];
struct edge {
	int v, c, next;
} e[M];
int dis[N];
int head[M];
int inq[N];
int cnt[N];
int top;
void add(int u, int v, int c)
{
	e[top].v = v;
	e[top].c = c;
	e[top].next = head[u];
	head[u] = top++;
}
bool spfa(int s, int t)
{
	memset(dis, inf, sizeof(dis));
	queue<int> que;
	que.push(s);
	dis[s] = 0;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		inq[now] = 0;
		for (int i = head[now]; i != -1; i = e[i].next) {
			int u = e[i].v;
			if (dis[u] > dis[now] + e[i].c) {
				dis[u] = dis[now] + e[i].c;
				if (inq[u])
					continue;
				cnt[u]++;
				if (cnt[u] > t)
					return true;
				inq[u]++;
				que.push(u);
			}
		}
	}
	return false;
}

int main()
{
	int n, ml, md;
	int u, v, c;
	scanf("%d %d %d", &n, &ml, &md);
	memset(head, -1, sizeof(head));
	for (int i = 0; i < ml; i++) {
		scanf("%d %d %d", &u, &v, &c);
		add(u, v, c);
	}
	for (int i = 0; i < md; i++) {
		scanf("%d %d %d", &u, &v, &c);
		add(v, u, -c);
	}
	int sta = spfa(1, n);
	if (sta)
		printf("-1\n");
	else if (dis[n] == inf)
		printf("-2\n");
	else
		printf("%d\n", dis[n]);
	return 0;
}
