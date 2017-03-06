#include <bits/stdc++.h>
using namespace std;
int get_id(int l, int r) {
  return l + r | l != r;
}
int main()
{
	int a = 1 << 3;
	cout << a << endl;
	int b = next_permutation(2, 3);
	cout << b << endl;
	cout << get_id(4 , 5) << endl;
	return 0;
}
