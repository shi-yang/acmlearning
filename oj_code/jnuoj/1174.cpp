#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int t = n;
		memset(a, 0, sizeof(a));
		while (n--) {
			int c;
			cin >> c;
			a[c] = 1;
			while (a[t]) {
				cout << t;
				t--;
				if (a[t])
					cout << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}
