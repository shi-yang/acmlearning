#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char s[105][105];
int main()
{
	int n, k, min_sec, max_sec;
	min_sec = max_sec = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n; i++)
		scanf("%s", s[i]);

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (strlen(s[i]) > strlen(s[j]))
				swap(s[i], s[j]);
	int len = strlen(s[n]);
	int len_count = 0;
	int len_min = 0;
	for (int i = 0; i < n; i++) {
		int len1 = strlen(s[i]);
		if (len1 == len) {
			len_count++;
		}
		if (len1 < len) {
			len_min++;
		}
	}
	if (len_min == 0) {
		min_sec = 1;
		int j = (len_count - 1) / k;
		max_sec = j * 5 + len_count;
	}
	if (len_min > 0) {
		int j = len_min / k;
		min_sec = j * 5 + len_min + 1;
		max_sec = ((len_min + len_count - 1) / k ) * 5 + len_min + len_count;
	}
	printf("%d %d\n", min_sec, max_sec);
  	return 0;
}
