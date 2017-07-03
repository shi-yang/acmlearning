#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1005;
const int M = 20005;
const int inf = 0x3f3f3f3f;
struct edge {
	int u, v, c;
	edge (){}
	edge (int u, int v, int c) : u(u), v(v), c(c) {}
} e[M];
int dis[N];
int top;
bool bellman(int n)
{
	memset(dis, inf, sizeof(dis));
	dis[1] = 0;
	for (int i = 0; i < n - 1; i++) {
		bool update = false;
		for (int j = 0; j < top; j++) {
			edge es = e[j];
			if (dis[es.v] > dis[es.u] + es.c) {
				dis[es.v] = dis[es.u] + es.c;
				update = true;
			}
		}
		if (!update)
			break;
	}
	for (int i = 0; i < top; i++) {
		if (dis[e[i].v] > dis[e[i].u] + e[i].c)
			return true;
	}
	return false;
}

int main()
{
	int n, ml, md;
	int u, v, c;
	scanf("%d %d %d", &n, &ml, &md);
	for (int i = 0; i < ml; i++) {
		scanf("%d %d %d", &u, &v, &c);
		e[top++] = edge(u, v, c);
	}
	for (int i = 0; i < md; i++) {
		scanf("%d %d %d", &u, &v, &c);
		e[top++] = edge(v, u, -c);
	}
	int sta = bellman(n);
	if (sta)
		printf("-1\n");
	else if (dis[n] == inf)
		printf("-2\n");
	else
		printf("%d\n", dis[n]);
	return 0;
}
