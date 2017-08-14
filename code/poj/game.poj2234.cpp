#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
	int m;
	while (~scanf("%d", &m)) {
		int ans = 0;
		while (m--) {
			int x;
			scanf("%d", &x);
			ans ^= x;
		}
		printf("%s\n", ans ? "Yes" : "No");
	}
	return 0;
}