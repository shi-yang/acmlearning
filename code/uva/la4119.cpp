#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll power(ll n, ll k, ll mod)
{
	ll res = 1;
	while (k) {
		if (k & 1) {
			res = res * n % mod;
		}
		n = n * n % mod;
		k >>= 1;
	}
	return res;
}
bool cal(string str, ll n)
{
	ll e = 0;
	ll sum = 0;
	char op = '+';
	ll last = 0;
	int i = 0;
	ll mod = 0;
	while (str[i] != '/') {
		i++;
	}
	for (int j = i + 1; j < str.size(); j++) {
		mod = mod * 10 + str[j] - '0';
	}
	for (i = 1; i < str.size();) {
		if (str[i] == '+' || str[i] == '-' || str[i] == ')') {
			if (op == '+') {
				sum += last;
			} else if (op == '-') {
				sum -= last;
			}
			if (str[i] == ')')
				break;
			op = str[i];
			i++;
		}
		ll v = 1;
		int flag = 1;
		if (isdigit(str[i])) {
			v = 0;
			for (int &j = i; isdigit(str[j]); j++) {
				v = v * 10 + str[j] - '0';
			}
			flag = 0;
		}
		if (str[i] == 'n') {
			e = 1;
			int found = 1;
			if (str[i + 1] == '^') {
				e = 0;
				i += 2;
				for (int &j = i; isdigit(str[j]); j++) {
					e = e * 10 + str[j] - '0';
				}
				found = 0;
			}
			last = v * power(n, e, mod);
			i += found;
		} else {
			last = v;
			i += flag;
		}
	}

	return !(sum % mod);
}
int main()
{
	string str;
	for (int cas = 1; cin >> str && str != "."; cas++) {
		int k = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '^') {
				k = 0;
				for (int j = i + 1; isdigit(str[j]); j++) {
					k = k * 10 + str[j] - '0';
				}
				break;
			}
			if (str[i] == 'n') {
				k = 1;
			}
		}
		bool ok = true;
		for (int i = 1; i <= k + 1; i++) {
			if (!cal(str, i)) {
				ok = false;
				break;
			}
		}
		if (ok)
			printf("Case %d: Always an integer\n", cas);
		else
			printf("Case %d: Not always an integer\n", cas);
	}
	return 0;
}