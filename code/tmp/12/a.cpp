#include <bits/stdc++.h>
using namespace std;
int main()
{
	string text;
	int ans = 0;
	while (getline(cin, text)) {
		string str;
		stringstream ss(text);
		while (ss >> str) {
			for (int i = 0; i < str.size(); i++) {
				str[i] = tolower(str[i]);
			}
			int npos;
			while ((npos = str.find("doge")) != -1) {
				str = str.substr(npos + 4);
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
