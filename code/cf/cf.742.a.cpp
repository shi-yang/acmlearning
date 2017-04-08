#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, l;
	scanf("%d", &n);
	if (n==0) {
		cout << 1 << endl;
		return 0;
	}
	switch (n % 4) {
	case 0:
		l = 6;
		break;
	case 1:
		l = 8;
		break;
	case 2:
		l = 4;
		break;
	case 3:
		l = 2;
		break;
	default:
		l = 6;
		break;
	}
	cout << l << endl;
	return 0;
}
