#include <bits/stdc++.h>
using namespace std;
string a, b;
int main()
{
	cin >> a >> b;
	printf("%d\n", a == b ? -1 : max(a.size(), b.size()));
	return 0;
}
