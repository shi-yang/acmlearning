#include <iostream>
#include <cstdio>
using namespace std;

int leap(int y)
{
	if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) {
		return 366;
	}
	return 365;
}
int first[] = {8, 14, 13, 12, 11, 10, 9};
int second[] = {1, 7, 6, 5, 4, 3, 2};
int main()
{
	int t;
	scanf("%d", &t);
	int kase = 1;
	while (t--) {
		string x, y;
		cin >> x >> y;
		char tmp[5];
		int year = 0, m = 0, d = 0, h = 0, mi = 0;
		for (int i = 0; i < 4; i++)
			year = year * 10 + x[i] - '0';
		for (int i = 5; i < 7; i++)
			m = m * 10 + x[i] - '0';
		for (int i = 8; i < 10; i++)
			d = d * 10 + x[i] - '0';
		for (int i = 0; i < 2; i++)
			h = h * 10 + y[i] - '0';
		for (int i = 3; i < 5; i++)
			mi = mi * 10 + y[i] - '0';
		int ba = 2007;
		int days = 4;
		while (ba != year) {
			days += leap(++ba);
			days %= 7;
		}
		string ans;
		if (m < 3 || m > 11) {
			ans = "PST";
		} else if (m > 3 && m < 11) {
			ans = "PDT";
		} else if (m == 3){
			days = first[days];
			if (d < days) ans = "PST";
			else if (d > days) ans = "PDT";
			else {
				if (h == 2)	ans = "Neither";
				if (h < 2) ans = "PST";
				if (h > 2)	ans = "PDT";
			}
		} else if  (m == 11) {
			days = second[days];
			if (d < days) ans = "PDT";
			else if (d > days) ans = "PST";
			else {
				if (h == 1)	ans = "Both";
				if (h < 1) ans = "PDT";
				if (h > 1)	ans = "PST";
			}
		}
		cout << "Case #" << kase++ << ": " << ans << endl;
	}
	return 0;
}
