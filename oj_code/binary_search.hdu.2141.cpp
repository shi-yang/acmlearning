#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 505;
int a[maxn];
int b[maxn];
int c[maxn];
int ab[maxn * maxn];
int l, m, n, cnt;
int inputdata(int a[], int k)
{
	for (int i = 0; i < k; i++)
		scanf("%d", &a[i]);
}
int solve(int x)
{
	if (x < ab[0] + c[0] || x > ab[cnt - 1] + c[n - 1]) {
		return 0;
	} else {
		bool found = false;
		for (int i = 0; i < n; i++) {
			int qq = x - c[i];
		    int f = 0, l = cnt - 1;  
		    int mid;  
		    while (f <= l) {  
		        mid = (f + l) / 2;  
		        if(ab[mid] == qq)  
		            return 1;  
		        else if(ab[mid] < qq)  
		            f = mid + 1;  
		        else  
		            l = mid - 1;  
		    }  
		}
	}
	return 0;
}
int main()
{
	int cas = 1;
	while (~scanf("%d%d%d", &l, &m, &n)) {
		printf("Case %d:\n", cas++);
		inputdata(a, l);
		inputdata(b, m);
		inputdata(c, n);
		cnt = 0;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < m; j++) {
				ab[cnt++] = a[i] + b[j];
			}
		}
		sort(ab, ab + cnt);
		sort(c, c + n);
		int s, x;
		scanf("%d", &s);
		while (s--) {
			scanf("%d", &x);
			if (solve(x)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}
