#include <bits/stdc++.h>
using namespace std;
int n, a[100001], x, t;
int main(){
	cin >> n;
	t = n;
	while (n--) {
		cin >> x;
		a[x] = 1;
		while (a[t])
			printf("%d ", t--);
		puts("");
	}
	return 0;
}
