#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
map<int, string> rec;
int main()
{
	int b, v, q;
	while (~scanf("%d %d", &b, &v)) {
		for (int i = 0; i < v; i++) {
			string str;
			int c;
			cin >> str >> c;
			mp[str] = c;
			rec[i] = str;
		}
		for (int i = 0; i < v; i++) {
			int c = mp[rec[i]];
			for (int j = 0; j < c; j++) {
				string str;
				cin >> str;
			}
		}
		scanf("%d", &q);
		while (q--) {
			string str;
			cin >> str;
			
		}
	}
	return 0;
}