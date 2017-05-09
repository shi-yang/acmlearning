#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	while (n--) {
		if (cnt == 0)
			cout << 'a';
		else if (cnt == 1)
			cout << 'a';
		else if (cnt == 2)
			cout << 'b';
		else if (cnt == 3)
			cout << 'b';
		cnt++;
		if (cnt == 4)
			cnt = 0;
	}
	cout << endl;
	return 0;
}
