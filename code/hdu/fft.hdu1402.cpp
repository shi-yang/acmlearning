#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int N = 50005;
int rev(int id, int len)
{
	int res = 0;
	for (int i = 0; (1 << i) < len; i++) {
		res <<= 1;
		if (id & (1 << i))
			res |= 1;
	}
	return res;
}
void fft(vector<complex<double> > &a, int len, int dft)
{
	vector<complex<double> > tmp;
	tmp.resize(len);
	for (int i = 0; i < len; i++) {
		tmp[rev(i, len)] = a[i];
	}
	for (int s = 1; (1 << s) <= len; s++) {
		int m = (1 << s);
		complex<double> wm = complex<double>(cos(dft * 2 * pi / m), sin(dft * 2 * pi / m));
		for (int k = 0; k < len; k += m) {
			complex<double> w = complex<double>(1, 0);
			for (int j = 0; j < (m >> 1); j++) {
				complex<double> t = w * tmp[k + j + (m >> 1)];
				complex<double> u = tmp[k + j];
				tmp[k + j] = u + t;
				tmp[k + j + (m >> 1)] = u - t;
				w = w * wm;
			}
		}
	}
	if (dft == -1) {
		for (int i = 0; i < len; i++) {
			tmp[i] = complex<double>(tmp[i].real() / len, tmp[i].imag() / len);
		}
	}
	a = tmp;
}
vector<complex<double> > a, b;
vector<int> ans;
char stra[N], strb[N];
int main()
{
	while (~scanf("%s %s", stra, strb)) {
		a.clear();
		b.clear();
		ans.clear();
		int lena = strlen(stra), lenb = strlen(strb);
		int la = 0, lb = 0;
		while ((1 << la) < lena)
			la++;
		while ((1 << lb) < lenb)
			lb++;
		int len = (1 << (max(la, lb) + 1)); 
		for (int i = 0; i < len; i++) {
			if (i < lena) {
				a.push_back(complex<double>(stra[lena - i - 1] - '0', 0));
			}
			if (i < lenb)
				b.push_back(complex<double>(strb[lenb - i - 1] - '0', 0));
		}
		a.resize(len);
		b.resize(len);
		fft(a, len, 1);
		fft(b, len, 1);
		for (int i = 0; i < len; i++) {
			a[i] = a[i] * b[i];
		}
		fft(a, len, -1);
		for (int i = 0; i < len; i++) {
			ans.push_back(int(a[i].real() + 0.5));
		}
		for (int i = 0; i < len - 1; i++) {
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
		bool flag = 0;
		for (int i = len - 1; i >= 0; i--) {
			if (ans[i]) {
				printf("%d", ans[i]);
				flag = 1;
			} else if (flag || i == 0) {
				printf("0");
			}
		}
		putchar('\n');
	}
	return 0;
}