#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 20005;
int n, m, r;
struct edge {
    int x, y, d;
    bool operator < (const edge &a) const{
        return d > a.d;
    }
} e[50005];
int f[maxn];
int root(int x)
{
    return x == f[x] ? x : f[x] = root(f[x]);
}
void kurskal()
{
    long long ans = (m + n) * 10000;
    for (int i = 0; i < r; i++) {
        int a = root(e[i].x), b = root(e[i].y);
        if (a != b) {
            f[a] = b;
            ans -= e[i].d;
        }
    }
    printf("%lld\n", ans);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //ios::sync_with_stdio(false);
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &r);
        for (int i = 0; i < maxn; i++)
            f[i] = i;
        for (int i = 0; i < r; i++) {
            int x, y, d;
            scanf("%d%d%d", &x, &y, &d);
            e[i].x = x + 10001, e[i].y = y, e[i].d = d;
        }
        sort(e, e + r);
        kurskal();
    }
    return 0;
}
