#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int primes[maxn];
void get_primes()
{
	for (int i = 2; i <= maxn; i++) {
		primes[i] = true;
	}
	primes[1] = false;
	for (int i = 0; i <= maxn; i++) {
		if (primes[i]) {
			for (int j = 2; j * i <= maxn; j++)
				primes[i * j] = false;
		}
	}
}
int main()
{
  //freopen("data.in", "r", stdin);
  get_primes();
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    cout << 1 << endl;
    return 0;
  }
  if (n == 2) {
    cout << 1 << endl;
    cout << 1 << ' ' << 1 << endl;
    return 0;
  }
  cout << 2 << endl;
  for (int i = 2; i <= n + 1; i++) {
    if (primes[i])
      cout << 1 << ' ';
    else
      cout << 2 << ' ';
  }
  cout << endl;
  return 0;
}
