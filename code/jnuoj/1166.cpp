#include <bits/stdc++.h>
using namespace std;
int main()
{
	int tt;
	cin >> tt;
	while (tt--) {
		string str;
		cin >> str;
		int ucnt = 0, lcnt = 0;
		for (int i = 0; i < str.size(); i++) {
			if ('a' <= str[i] && str[i] <= 'z') {
				lcnt++;
			} else {
				ucnt++;
			}
		}
		for (int i = 0; i < str.size(); i++) {
			if (lcnt >= ucnt) {
				printf("%c", tolower(str[i]));
			} else {
				printf("%c", toupper(str[i]));
			}
		}
		cout << endl;
	}
	return 0;
}
