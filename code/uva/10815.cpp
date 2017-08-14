#include <bits/stdc++.h>
using namespace std;
set<string> s;
int main()
{
	string str;
	while (cin >> str) {
		string tmp;
		for (int i = 0; i < str.size(); i++) {
			if (isalpha(str[i])) {
				str[i] = tolower(str[i]);
				tmp += str[i];
			} else {
				s.insert(tmp);
				tmp = "";
			}
		}
		s.insert(tmp);
	}
	for (set<string>::iterator it = s.begin(); it != s.end(); it++) {
		if (*it == "")
			continue;
		cout << *it << endl;
	}
	return 0;
}