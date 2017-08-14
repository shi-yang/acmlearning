#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1050;

int value[maxn];
int w[maxn];
int f[maxn];
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        memset(f, 0, sizeof(f));
        int m, n;
        cin >> m >> n;
        for (int i = 0; i < m; i++)
            cin >> value[i];
        for (int i = 0; i < m; i++)
            cin >> w[i];
        for (int i = 0; i < m; i++)
            for (int j = n; j >= w[i]; j--)
                f[j] = max(f[j], f[j - w[i]] + value[i]);

        cout << f[n] << endl;
    }
    return 0;
}