#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 33;
int n, k, mod;
struct matrix {
	int a[N][N];
	int r;
	matrix(int r) : r(r) {}
	void makei() {
		memset(a, 0, sizeof(a));
		for (int i = 0; i < r; i++) {
			a[i][i] = 1;
		}
	}
	void in() {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < r; j++) {
				scanf("%d", &a[i][j]);
			}
		}
	}
	void out() {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < r; j++) {
				if (j) putchar(' ');
				printf("%d", a[i][j]);
			}
			printf("\n");
		}
	}
	matrix operator + (const matrix & m) {
		matrix tmp(r);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < r; j++) {
				tmp.a[i][j] = (a[i][j] + m.a[i][j]) % mod;
			}
		}
		return tmp;
	}
	matrix operator * (const matrix & m) {
		matrix result(r);
		for (int k = 0; k < r; k++) {
			for (int i = 0; i < r; i++) {
				result.a[k][i] = 0;
				for (int j = 0; j < r; j++) {
					result.a[k][i] =(result.a[k][i] + a[k][j] * m.a[j][i]) % mod;
				}
			}
		}
		return result;
	}
};
inline matrix power(const matrix & m, int k)
{
	matrix res(m.r);
	res.makei();
	matrix base = m;
	while (k) {
		if (k & 1)
			res = res * base;
		k >>= 1;
		base = base * base;
	}
	return res;
}
matrix sum(matrix m, int n)
{
	if (n == 1)
		return m;
	int r = m.r;
	matrix e(r);
	e.makei();
	if (n & 1) {
		return (e + power(m, (n - 1) >> 1)) * sum(m, (n - 1) >> 1) + power(m, n);
	} else {
		return (e + power(m, n >> 1)) * sum(m, n >> 1);
	}
}
int main()
{
	scanf("%d %d %d", &n, &k, &mod);
	matrix qq(n);
	qq.in();
	matrix ans = sum(qq, k);
	ans.out();
	return 0;
}
