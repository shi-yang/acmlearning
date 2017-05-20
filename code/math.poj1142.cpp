#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int sum(int x)
{
	int v = 0;
	while (x) {
		v += x % 10;
		x /= 10;
	}
	return v;
}
int main()
{
	int n;
	while (~scanf("%d", &n) && n) {
		while (++n) {
			int s = 0;
			int now = n;
			for (int i = 2; i * i <= n; i++) {
				if (now % i == 0) {
					while (now % i == 0) {
						now /= i;
						s += sum(i);
					}
				}
			}
			if (now == n)	continue;
			if (now != 1)
				s += sum(now);
			if (sum(n) == s) {
				printf("%d\n", n);
				break;
			}
		}
	}
	return 0;
}
