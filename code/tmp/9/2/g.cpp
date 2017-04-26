#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 8005;
map<pair<int, int>, int> mp;
struct edge {
	int x, y, w;
	edge() {}
	edge(int x, int y, int w) : x(x), y(y), w(w) {}
} e[N];
vector<edge> G[N];
int inq[N];
int n;
int cnt;
int spfa()
{
	
}
int main()
{
	int tt;
	scanf("%d", &tt);
	for (int qq = 1; qq <= tt; qq++) {
		scanf("%d", &n);
		cnt = 0;
		for (int i = 0; i < n; i++) {
			int x1, x2, y1, y2, w;
			cin >> x1 >> y1 >> x2 >> y2 >> w;
			pair<int, int> p1 = make_pair(x1, y1);
			pair<int, int> p2 = make_pair(x2, y2);
			if (!mp[p1]) {
				mp[p1] = cnt++;
			}
			if (!mp[p2]) {
				mp[p2] = cnt++;
			}
			//edge(x2, y2, w);
			G[mp[p1]].push_back(edge(x2, y2, w));
		}
		
		printf("Case #%d: %d\n", qq, ans),
	}
	return 0;
}
