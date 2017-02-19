#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 355;
int balls[maxn][maxn];
int n;
int main()
{
	scanf("%d", &n);
	memset(balls, 0, sizeof(balls));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &balls[i][j]);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			balls[i][j] += max(balls[i + 1][j], balls[i + 1][j + 1]);
		}
	}
	printf("%d\n", balls[0][0]);
	return 0;
}
