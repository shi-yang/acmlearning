#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
int n, m, res = 1;
vector<int> e[10005];
bool vst[10005];
int so[10005];
bool c[10005][6];
void bfs(int maxn)
{
	pair<int, int> now;
	queue<pair<int, int>> q;
	q.push(make_pair(maxn, -1));
	vst[maxn] = true;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		if (now.second != -1 && vst[now.first] == false)
		{
			if (c[now.first][now.second] == true)
				so[now.first] -= 1;
			vst[now.first] = true;
		}
		for (int i = 0; i < 6; i++)
		{
			if (c[now.first][i] && i != now.second)
				for (int j = 0; j < e[now.first].size(); j++)
				{
					if(!vst[e[now.first][j]])
						q.push(make_pair(e[now.first][j], i));
				}
		}
	}
}

int main()
{
	int x, y, t;
	memset(vst, false, sizeof(vst));
	memset(so, 0, sizeof(so));
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &c[i][j]);
			if (c[i][j])
				so[i]++;
		}

	int maxs = 0, maxn;
	for (int i = 1; i <= n; i++)
		if (e[i].size() > maxs)
		{
			maxs = e[i].size();
			maxn = i;
		}
	bfs(maxn);
	for (int i = 1; i <= n; i++)
	{
		res *= so[i];
		if (res > 10000009)
			res %= 10000009;
	}
	cout << res << endl;

	return 0;
}
