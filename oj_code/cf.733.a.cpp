#include <bits/stdc++.h>
using namespace std;
char s[105];
int main()
{
	scanf("%s", s);
	int a = -1, k = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
			s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
			a = max(a, k);
			k = 0;
		} else {
			k++;
		}
	}
	cout << max(k, a) + 1 << endl;
  	return 0;
}
