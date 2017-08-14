#include <bits/stdc++.h>
using namespace std;
string in[105];
string ans[105];
int vis[105];
int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--) {
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		int num = 0;
		for (int i = 0; i < n; i++) {
			cin >> in[i];
		}
		ans[num++] = in[0];
		vis[0] = true;
		int last = 0;
		int res = in[0].size();
		while (num != n) {
			int pos = 0, mx = 0;
			for (int j = 1; j < n; j++) {
				if (vis[j])
					continue;
				if (!pos)
					pos = j;
				for (int k = 0; k < min(in[j].size(), in[last].size()); k++) {
					if (in[j][k] != in[last][k]) {
						break;
					}
					if (k + 1 > mx) {
						mx = k + 1;
						pos = j;
					}
				}
			}
			last = pos;
			ans[num++] = in[pos];
			vis[pos] = true;
			res += in[pos].size() - mx;
		}
		cout << res << endl;
		for (int i = 0; i < n; i++) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}