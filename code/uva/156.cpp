#include <bits/stdc++.h>
using namespace std;
map<string, int> cc;
map<string, string> dict;
set<string> s;
int main()
{
	string str;
	while (cin >> str && str != "#") {
		string tmp = str;
		for (int i = 0; i < tmp.size(); i++) {
			tmp[i] = tolower(tmp[i]);
		}
		sort(tmp.begin(), tmp.end());
		cc[tmp]++;
		dict[tmp] = str;
	}
	for (map<string, int>::iterator it = cc.begin(); it != cc.end(); it++) {
		if ((*it).second == 1) {
			s.insert(dict[(*it).first]);
		}
	}
	for (set<string>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}