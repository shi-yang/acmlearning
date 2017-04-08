#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
int a[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n - 2; i++) {
		if (a[i] + a[i + 1] > a[i + 2]) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
