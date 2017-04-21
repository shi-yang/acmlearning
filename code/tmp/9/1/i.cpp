#include <iostream>
#include <cstdio>

using namespace std;
const int N = 105;
char mp[N][N];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int h, w;
		scanf("%d %d", &h, &w);
		for (int i = 0; i < h; i++)
			scanf("%s", mp[i]);

	}
	return 0;
}
