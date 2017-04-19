#include <stdio.h>

//最大公约数
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

//素数打表
const int maxn = 1000;
bool primes[maxn];
void get_primes()
{
	memset(primes, true, sizeof(primes));
	for (int i = 2; i <= sqrt(n + 0.5); i++) {
		if (primes[i]) {
			for (int j = i * i; j <= n; j += i) {
				primes[j] = false;
			}
		}
	}
}


//O(n)
int get_primes()
{
	int n;
	vector<int> primes;
	bool is_primes[n + 1];
	memset(is_primes, true, sizeof(is_primes));
	for (int i = 2; i <= n; i++) {
		if (is_primes[i])
			primes.push_back(i);
		for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
			is_primes[i * primes[j]] = false;
			if (i % primes[j] == 0) {
				break;
			}
		}
	}
}

void ex_gcd(int a, int b, int &d, int &x, int &y)
{
	if (!b) {
		x = 1, y = 0, d = a;
	} else {
		gcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}
