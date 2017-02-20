#include <bits/stdc++.h>
using namespace std;
char str[105];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", str);
	int c_t, c_g;

	for (int i = 0; i < n; i++) {
		if (str[i] == 'G')
			c_g = i;
		else if (str[i] == 'T')
			c_t = i;
	}

	if (c_t < c_g) {
		swap(c_t, c_g);
	}
	bool can = false;
	for (int i = 0; i < n / k + 1; i++) {
		if (str[c_g] == '#') {
			break;
		} else if (c_g == c_t){
			can = true;
			break;
		} else {
			c_g += k;
		}
	}
	printf("%s\n", can ? "YES" : "NO" );
	return 0;
}
