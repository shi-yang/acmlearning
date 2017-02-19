#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int, vector<int>, greater<int> > que;
int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		long long sum = 0;
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			que.push(tmp);
		}
		while (que.size() > 1) {
			int a = que.top();
			que.pop();
			int b = que.top();
			que.pop();
			que.push(a + b);
			sum += (a + b);
		}
		cout << sum << endl;
	}
	return 0;
}
