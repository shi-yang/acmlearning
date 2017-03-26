#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
vector<int> e[maxn];
int n;
int color[maxn];
int ans;
void dfs(int x, int f)
{
	int t = 1;
	for (int i = 0; i < e[x].size(); i++) {
		int c = e[x][i];
		if (!color[c]) {
			while (t == color[x] || t == color[f])
				t++;
			color[c] = t++;
			ans = max(ans, color[c]);
			dfs(c, x);
		}
	}
}
int main()
{
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  color[1] = 1;
  dfs(1, 0);
  cout << ans << endl;
  for (int i = 1; i <= n; i++)
  	cout << color[i] << ' ';
  return 0;
}
