#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1e6;
int a[maxn];
int main()
{
	int n;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int m = (n + 1) >> 1;
		sort(a, a + n);
		printf("%d\n", a[m]);
	}
	return 0;
}
