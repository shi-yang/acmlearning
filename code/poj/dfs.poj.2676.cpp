#include <iostream>
using namespace std;
int maz[9][9];
bool flag;
bool check(int n, int v)
{
	int x = n % 9;
	int y = n / 9;
	for (int i = 0; i < 9; i++) {
		if (maz[x][i] == v || maz[i][y] == v)
			return false;
	}
	x = x / 3 * 3;
	y = y / 3 * 3;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (maz[i][j] == v)
				return false;
		}
	}
	return true;
}
void dfs(int n)
{
	int x = n % 9;
	int y = n / 9;
	if (n > 80 || flag) {
		flag = true;
		return ;
	}
	if (maz[x][y] != 0) {
		dfs(n + 1);
	} else {
		for (int i = 1; i <= 9; i++) {
			if (check(n, i)) {
				maz[x][y] = i;
				dfs(n + 1);
				if (flag)
					return ;
				maz[x][y] = 0;
			}
		}
	}
}
int main()
{
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		for (int i = 0; i < 9; i++) {
			cin >> s;
			for (int j = 0; j < 9; j++) {
				maz[i][j] = s[j] - '0';
			}
		}
		flag = false;
		dfs(0);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << maz[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
