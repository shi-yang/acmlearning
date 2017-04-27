#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    stack<int> num;
    stack<char> op;
    int ans;
    string line;
    getline(cin, line)
    string str;
    stringstream ss(line);
    char cu = 0;
    while (ss >> str) {
      int v = 0;
      if (str[0] >= '0' && str[0] <= '9') {
        for (int i = 0; i < str.size(); i++) {
          v = v * 10 + str[i] - '0';
        }
        if (ch != 0) {
          int tmp = num.top();
          int sum;
          num.pop();
          switch(ch) {
            case '*': sum = tmp * v; break;
            case '/': sum = tmp / v; break;
            case '%': sum = tmp % v; break;
          }
          num.push(sum);
        } else {
          num.push(v);
          ch = 0;
        }
      } else if (str[0] == '+' || str[0] == '-') {
        op.push(str[0]);
      } else {
        ch = str[0];
      }
    }
    while (!op.empty()) {
    
    } 
    printf("%d\n", ans);
  }
  return 0;
}