#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <string>
using namespace std;

const int N = 35;
map<string, int> mp;
vector<pair<int, double> > G[N];
int cnt[N];
int inq[N];
double dis[N];
bool spfa(int s, int n)
{
	queue<int> que;
	que.push(s);
	for (int i = 0; i <= N; i++) {
		dis[i] = 0;
		inq[i] = 0;
		cnt[i] = 0;
	}
	inq[s] = 1;
	dis[s] = 1;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		inq[now] = 0;
		for (int i = 0; i < G[now].size(); i++) {
			int v = G[now][i].first;
			if (dis[v] < dis[now] * G[now][i].second) {
				dis[v] = dis[now] * G[now][i].second;
				if (inq[v])
					continue;
				cnt[v]++;
				if (cnt[v] > n)
					return true;
				inq[v] = 1;
				que.push(v);
			}
		}
	}
	return false;
}

int main()
{
	int n, k;
	int cas = 1;
	while (~scanf("%d", &n) && n) {
		for (int i = 1; i <= n; i++) {
			string str;
			cin >> str;
			mp[str] = i;
			G[i].clear();
		}
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			string x, y;
			double m;
			cin >> x >> m >> y;
			G[mp[x]].push_back(make_pair(mp[y], m));
		}
		if (spfa(1, n)) {
			printf("Case %d: Yes\n", cas++);
		} else {
			printf("Case %d: No\n", cas++);
		}
	}
	return 0;
}
