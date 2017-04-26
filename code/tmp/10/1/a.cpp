#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if (x == 1)
				a++;
			if (x == 2)
				b++;
		}
		if (a > b)
			cout << "Kobayashi" << endl;
		else if (a == b)
			cout << "Draw" << endl;
		else
			cout << "Tohru" << endl;
	}
	return 0;
}
