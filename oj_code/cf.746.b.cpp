#include <bits/stdc++.h>
using namespace std;
char s[2345], tmp[2345];
int main()
{
	int n;
	cin >> n;
	scanf("%s", s);
	int k = n - 1;
	for (int i = n - 1; i >= 0; i -= 2) {
		tmp[k--] = s[i];
	}
	k = 0;
	for (int i = n - 2; i >= 0; i -= 2) {
		tmp[k++] = s[i];
	}
	printf("%s\n", tmp);
    return 0;
}
