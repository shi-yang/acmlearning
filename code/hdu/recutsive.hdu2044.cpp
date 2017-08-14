#include <bits/stdc++.h>
using namespace std;
long long a[55];
int main()
{
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= 55; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	int n;
	scanf("%d", &n);
	while (n--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%lld\n", a[y - x]);
	}
	return 0;
}
