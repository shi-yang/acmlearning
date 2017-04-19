#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
inline int power(int n, int k)
{
	int res = 1;
	while (k > 0) {
		if (k & 1)
			res = res * n % 7;
		res = res * n * n % 7;
		k >>= 1;
	}
	return res;
}
char str[][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
vector<int> ta;
void init()
{
	int t = 6;
	for (int i = 1; i <= 1000; i++) {
		t += power(i, i);
		t %= 7;
		ta.emplace_back(t);
	}
	for (int i = 0; i < 1000; i++) {
		cout << str[ta[i]] << endl;
	}
}
int main()
{
	int t;
	init();
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int ans = 6;
		for (int i = 1; i <= n; i++) {
			ans += power(i, i);
			ans %= 7;
		}
		printf("%s\n", str[ans]);
	}
	return 0;
}
