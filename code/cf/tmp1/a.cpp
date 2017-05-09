#include <bits/stdc++.h>
using namespace std;
int main()
{
	int l, r;
	scanf("%d %d", &l, &r);
	int t = r - l;
	if (t == 0) {
		cout << r << endl;
	} else {
		cout << 2 << endl;
	}
	return 0;
}
