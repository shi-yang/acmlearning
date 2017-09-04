#include <bits/stdc++.h>
using namespace std;
const int N = 30;
vector<int> G[N];
map<string, int> num;
map<int, string> name;
int vis[N], path[N];
void bfs(int from, int to)
{
	queue<int> que;
	que.push(from);
	memset(vis, 0, sizeof(vis));
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (auto v : G[now]) {
			if (!vis[v]) {
				vis[v] = 1;
				path[v] = now;
				if (v == to)
					return;
				que.push(v);
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	bool flag = 0;
	while (t--) {
		if (flag) {
			cout << endl;
		}
		flag = 1;
		for (int i = 0; i < N; i++) {
			G[i].clear();
		}
		num.clear();
		name.clear();
		int n, m;
		scanf("%d %d", &n, &m);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			string x, y;
			cin >> x >> y;
			if (!num[x]) {
				num[x] = ++cnt;
				name[cnt] = x;
			}
			if (!num[y]) {
				num[y] = ++cnt;
				name[cnt] = y;
			}
			G[num[x]].push_back(num[y]);
			G[num[y]].push_back(num[x]);
		}
		while (m--) {
			string x, y;
			cin >> x >> y;
			int from = num[x], to = num[y];
			bfs(from, to);
			stack<string> s;
			for (int i = to; i != from; i = path[i]) {
				s.push(name[i]);
			}
			cout << x[0];
			while (!s.empty()) {
				cout << s.top()[0];
				s.pop();
			}
			cout << endl;
		}
	}
	return 0;
}