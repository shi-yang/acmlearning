#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > g;
int main()
{
	int n, p;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		g.emplace_back(make_pair(a, b));
	}
	return 0;
}
