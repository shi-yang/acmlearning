#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	int len = s.size();
	if (len == 1) {
		cout << "YES" << endl;
		return 0;
	}
	for (int i = 0; i < len / 2; i++) {
		if (s[i] != s[len - i - 1])
			cnt++;
	}
	if (cnt == 1 || (cnt == 0 && (len & 1) == 1))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
