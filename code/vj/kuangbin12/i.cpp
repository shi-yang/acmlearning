#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
int n;
int a[N];
int t[N];
int main()
{
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		int cnt = 1;
		t[0] = a[0];
		for (int i = 1; i < n; i++) {
			int ok = false;
			for (int j = 0; j < cnt; j++) {
				if (t[j] > a[i]) {
					ok = true;
					t[j] = a[i];
					break;
				}
			}
			if (!ok) {
				t[cnt++] = a[i];
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}