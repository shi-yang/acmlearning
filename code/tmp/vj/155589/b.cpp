#include <bits/stdc++.h>
using namespace std;
int c[5];
int a[1005];
int b[1005];
int main()
{
  for (int i = 0; i < 4; i++)
    cin >> c[i];
  int n, m;
  cin >> n >> m;
  int suma = 0, sumb = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  	suma += min(c[0] * a[i], c[1]);
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
   	sumb += min(c[0] * b[i], c[1]);
  }
  suma = min(suma, c[2]), sumb = min(sumb, c[2]);
  cout << min(c[3], suma + sumb) << endl;
  return 0;
}
