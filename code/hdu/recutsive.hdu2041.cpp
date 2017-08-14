#include <bits/stdc++.h>
using namespace std;
const int N = 60;
long long f[N];
int main()
{
	int t;
	f[1] = 1;
	f[0] = 0;
	for (int i = 2; i <= N; i++)
		f[i] = f[i - 1] + f[i - 2];
	scanf("%d", &t);
	while (t--) {
		int a;
		scanf("%d", &a);
		printf("%lld\n", f[a]);
	}
	return 0;
}