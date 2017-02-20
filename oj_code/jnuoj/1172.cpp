#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
bool primes[maxn];
void get_p()
{
	for (int i = 2; i <= maxn; i++) {
		primes[i] = true;
	}
	primes[1] = false;
	for (int i = 1; i <= maxn; i++) {
		if (primes[i]) {
			for (int j = 2; j * i <= maxn; j++) {
				primes[i * j] = false;
			}
		}
	}
}
int main()
{
	get_p();
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (primes[i])
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | 二次开发： Semprathlon | Current Style: Original.

Select Style:   Fluid Width?
 
