/*
  完全背包问题
 */
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int f[10050];
int v[3] = {150, 200, 350};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        memset(f, 0, sizeof(f));
        int n;
        cin >> n;
        for (int i = 0; i < 3; i++)
            for (int j = v[i]; j <= n; j++)
                f[j] = max(f[j], f[j - v[i]] + v[i]);
        cout << n - f[n] << endl;
    }
    return 0;
}
