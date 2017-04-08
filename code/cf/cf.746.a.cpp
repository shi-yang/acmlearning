#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
int a[maxn], b[maxn];

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int k = 0;
	for (int i = 1; i <= a; i++) {
		if (b >= i * 2 &&  c >= i * 4)
			k++;
	}
	cout << k * 7 << endl;
    return 0;
}
