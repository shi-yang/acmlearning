#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1234 * 1234;
typedef long long ll;
int n, m, k;
struct edge {
	int l, r;
	bool operator < (const edge & a) const {
		if (l != a.l)
			return l < a.l;
		return r < a.r;
	}
} e[maxn];
ll merge_count(vector<int> & a)
{
	int n = a.size();
	if (n <= 1)
		return 0;
	ll cnt = 0;
	vector<int> b(a.begin(), a.begin() + n / 2);
	vector<int> c(a.begin() + n / 2, a.end());

	cnt += merge_count(b);
	cnt += merge_count(c);

	int ai = 0, bi = 0, ci = 0;
	while (ai < n) {
		if (bi < b.size() && (ci == c.size() || b[bi] <= c[ci]))
			a[ai++] = b[bi++];
		else {
			cnt += n / 2 - bi;
			a[ai++] = c[ci++];
		}
	}
	return cnt;
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int qq = 1; qq <= t; qq++) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < k; i++)
			scanf("%d %d", &e[i].l, &e[i].r);
		sort(e, e + k);
		vector<int> a;
		for (int i = 0; i < k; i++)
			a.push_back(e[i].r);
		ll ans = merge_count(a);
		printf("Test case %d: %lld\n", qq, ans);
	}
	return 0;
}
