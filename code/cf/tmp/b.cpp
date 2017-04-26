#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	string str[55];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	int len = str[0].size();
	int ans = 1e9;
	for (int k = 0; k < n; k++) {
		int t = 0;
		for (int i = 0; i < n; i++) {
			if (i == k)
				continue;
			string s = str[i];
			for (int j = 0; j < len; j++) {
				if (s == str[k]) {
					break;
				} else {
					string ss = s;
					s = s.substr(1, len - 1) + ss.substr(0, 1);
					t++;
				}
			}
			if (s != str[k]) {
				ans = -1;
				break;
			}
		}
		ans = min(ans, t);
	}
	cout << ans << endl;
	return 0;
}
