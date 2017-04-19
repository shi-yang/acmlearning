#include <bits/stdc++.h>
using namespace std;
const int N = 30000005;
int ans[N];
int main()
{
	for (int c = 1; c + c < N; c++) {
		for (int a = c + c; a < N; a += c) {
			int b = a ^ c;
			if (a == b + c)
				ans[a]++;
		}
	}
	for (int i = 1; i < N; i++)
		ans[i] = ans[i] + ans[i - 1];
	int n, t;
	scanf("%d", &t);
	for (int cc = 1; cc <= t; cc++) {
		scanf("%d", &n);
		printf("Case %d: %d\n", cc, ans[n]);
	}
	return 0;
}
