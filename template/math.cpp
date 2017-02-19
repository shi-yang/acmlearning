#include <stdio.h>

//最大公约数
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

//素数打表
const int maxn = 1000;
int primes[maxn];
void get_primes()
{
	for (int i = 2; i <= maxn; i++) {
		primes[i] = true;
	}
	primes[1] = false;
	for (int i = 0; i <= maxn; i++) {
		if (primes[i]) {
			for (int j = 2; j * i <= maxn; j++)
				primes[i * j] = false;
		}
	}
}
