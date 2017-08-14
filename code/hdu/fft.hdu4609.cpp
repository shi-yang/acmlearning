#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int N = (int) 1e5 + 5;
int a[N];
int rev(int i, int len)
{

}
void fft(vector<complex<double> > &a, int len, int dft)
{
	vector<complex<double> > tmp;
	tmp.resize(len);
	for (int i = 0; i < len; i++) {
		tmp[rev(i, len)] = a[i];
	}
	for (int s = 1; 1 << s <= len; s++) {
		int m = 1 << s;
		complex<double> wm = complex<double>(cos(2 * PI * dft / m), sin(2 * PI * dft / m));
		for (int k = 0; k < len; k += m) {
			complex<double> w = complex<double>(1, 0);
			for (int j = 0; j < (m >> 1); j++) {
				complex<double> t = tmp[k + j];
				complex<double> u = w * tmp[k + j + (m >> 1)];
				tmp[k + j] = t + u;
				tmp[k + j + (m >> 1)] = t - u;
				w = wm * w;
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
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
	}
	return 0;
}