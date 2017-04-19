#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int ans = 0;
	int flag = 0;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == 'V' && str[i + 1] == 'K') {
			ans++;
		}
		if (str[i] == 'V' && str[i + 1] == 'V' && str[i + 2] != 'K') {
			flag = 1;
		}
		if (str[i] == 'K' && str[i + 1] == 'K' && str[i + 2] == 'K') {
			flag = 1;
		}
	}
	ans += flag;
	cout << ans << endl;
	return 0;
}
