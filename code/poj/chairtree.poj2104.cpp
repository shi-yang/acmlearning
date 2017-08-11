#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = (int) 1e5 + 10;
int n, q;
vector<int> v;
struct node {
	int l, r, sum;
} t[N * 40];
int cnt;
void update(int l, int r, int &x, int y, int pos)
{
	t[++cnt].sum++, x = cnt;
	int m = l + r >> 1;
	if (pos <= m)
		update(l, m, x, y, pos);
	else
		update(m + 1, r, x, y, pos);
}
int query(int l, int r, int x, int y, int k)
{
	
}
int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		v.push_back(a[i]);
	}
	sort(v + 1, v + n + 1);
	for (int i = 1; i <= n; i++) {
		update(1, n, t[i], t[i - 1], i);
	}
	while (q--) {
		int x, y, k;
		scanf("%d %d %d", &x, &y, &k);
		printf("%d\n", v[query(1, n, t[x - 1], t[y], k) - 1]);
	}
	return 0;
}