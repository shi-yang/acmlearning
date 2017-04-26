#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		string str;
		map<string, int> sti;
		map<int, string> its;
		int cnt = 0;
		int n, q;
		scanf("%d %d", &n, &q);
		int c;
		scanf("%d", &c);
		for (int i = 0; i < c; i++)	{
			cin >> str;
			sti[str] = ++cnt;
			its[cnt] = str;
		}
		int val[22];
		int tmp[105];
		for (int i = 0; i < q; i++) {
			val[i] = i + 1;
			int m;
			scanf("%d", &m);
			for (int j = 0; j < m; j++) {
				cin >> str;
				tmp[sti[str]] += val[i];
			}
		}
		for (int i = 0; i < n; i++)	{
			int sum = 0;
			for (int j = 0; j < q; j++) {
				int x;
				scanf("%d", &x);
				if (x == 1)
					sum += val[j];
			}
			cout << sum << endl;
			int co = 0, pos;
			for (int j = 1; j <= cnt; j++) {
				if (tmp[j] == sum) {
					co++;
					pos = j;
				}
			}
			if (co == 1) {
				cout << its[pos] << endl;
			} else {
				cout << "Let's go to the library!!" << endl;
			}
		}
	}
	return 0;
}
