#include <bits/stdc++.h>
using namespace std;
int main()
{
	int tmp[10][10];
	int a[10];
	int n = 5;
	for (int i = 1; i <= 5; i++)
		a[i] = i;
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			if (i == n - 2) {
				tmp[i][j] = a[j] + a[j + 1];
			} else {
				tmp[i][j] = tmp[i + 1][j] + tmp[i + 1][j + 1];
			}
		}
	}
	cout << tmp[0][0] << endl;
	return 0;
}
