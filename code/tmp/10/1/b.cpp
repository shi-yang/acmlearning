#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[1234];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		if (n < 10 || n > 13) {
			printf("No\n");
			continue;
		}
		sort(a, a + n);
		if (a[0] != 1 || a[1] != 1) {
			printf("No\n");
			continue;
		}
		int ok = 1;
		for (int i = 1; i < n - 2; i++) {
			if (a[i + 1] - a[i] > 2) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
