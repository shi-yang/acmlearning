#include <iostream>
#include <cstdio>
using namespace std;
void build(int l, int r, int rt)
{
	if (l == r) {
		
	} else {
		int m = (l + r) >> 1;
		build(l, m, rt << 1);
		build(m + 1, r, rt << 1 | 1);
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		
	}
	return 0;
}
