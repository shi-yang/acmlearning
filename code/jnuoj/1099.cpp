#include <iostream>
using namespace std;
int main()
{
	string s;
	while(cin >> s) {
		int i = 0;
		while (i < s.length()) {
			string result = s.substr(i, 4);
			if(result == "iPod" || result == "iPad") {
				cout << "MAI MAI MAI!" << endl;
				i += 4;
			} else if (result == "Sony") {
				cout << "SONY DAFA IS GOOD!" << endl;
				i += 4;
			} else if (s.substr(i, 5) == "Apple" || s.substr(i, 6) == "iPhone") {
				cout << "MAI MAI MAI!" << endl;
				i += 5;
			} else {
				i++;
			}
		}
	}
	return 0;
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | 二次开发： Semprathlon | Current Style: Original.

Select Style:   Fluid Width?
 
