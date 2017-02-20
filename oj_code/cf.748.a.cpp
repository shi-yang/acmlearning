#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	k--;
	printf("%d %d %c", k / (m * 2) + 1, (k % (m * 2)) / 2 + 1, k % 2 == 0 ? 'L' : 'R');
	return 0;
}
