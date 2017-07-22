#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int mx[N << 3];
void insert(int v, int x, int l, int r, int rt)
{ 
	if (l == r) {
		mx[rt] = x;
		return;
	}
	int mid = (l + r) >> 1;
	if (v <= mid)
		insert(v, x, l, mid, rt << 1);
	else
		insert(v, x, mid + 1, r, rt << 1 | 1);
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}
int query(int ll, int rr, int l, int r, int rt)
{
	if (ll <= l && r <= rr) {
		return mx[rt];
	}
	int mid = (l + r) >> 1;
	int res = 0;
	if (ll <= mid)
		res = max(res, query(ll, rr, l, mid, rt << 1));
	if (rr > mid)
		res = max(res, query(ll, rr, mid + 1, r, rt << 1 | 1));
	return res;
}
int m, d;
int main()
{
	int t = 0, cnt = 0;
	scanf("%d %d", &m, &d);
	while (m--) {
		char s[5];
		int x;
		scanf("%s %d", s, &x);
		if (s[0] == 'A') {
			insert(++cnt, (x + t) % d, 1, N, 1);
		} else {
			printf("%d\n", t = query(cnt - x + 1, cnt, 1, N, 1));
		}
	}
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int num[N], que[N];
int main()
{
	int m, d, t = 0, top = 0;
	scanf("%d %d", &m, &d);
	while (m--) {
		char s[5];
		int x;
		scanf("%s %d", s, &x);
		if (s[0] == 'A') {
			num[top++] = (x + t) % d;
			for (int i = top - 1; i >= 0 && que[i] < num[top - 1]; i--) {
				que[i] = num[top - 1];
			}
		} else {
			printf("%d\n", t = que[top - x]);
		}
	}
	return 0;
}*/