#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while (cin >> n, n) {
		if (n & 1) {
			printf("Bob\n");
		} else {
			printf("Alice\n");
		}
	}
	return 0;
}