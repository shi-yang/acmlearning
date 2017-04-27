#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, i, is = 1;  // 我用 is 来表示它是不是一个素数，如果 is = 1就是素数， is = 0 就不是素数。
	scanf("%d"， &n);

	// i 从 2 开始，到 n - 1
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
		//这里 n % i == 0, 表示 判断 n 除 i 的余数是否为 0， 为 0 说明 i 是 n 的因子
			is = 0;
			break;
		}
	}
	return 0;
}
