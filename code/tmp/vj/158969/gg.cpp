#include <iostream>
#include <cstdio>
using namespace std;

int get(char t, int a, int b)
{
  int ans;
  switch(t) {
    case '*': ans = a * b; break;
    case '/': ans = a / b; break;
    case '%': ans = a % b; break;
    case '+': ans = a + b; break;
    case '-': ans = a - b; break;
  }
  return ans;
}
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    char op1[5], op2[5];
    scanf("%d %s %d %s %d", &a, op1, &b, op2, &c);
    int ans;
    if (op1[0] == '*' || op1[0] == '/' || op1[0] == '%') {
      ans = get(op1[0], a, b);
      ans = get(op2[0], ans, c);
    } else if (op2[0] == '*' || op2[0] == '/' || op2[0] == '%') {
      ans = get(op2[0], b, c);
      ans = get(op1[0], a, ans);
    } else {
      ans = get(op1[0], a, b);
      ans = get(op2[0], ans, c);
    }
    printf("%d\n", ans);
  }
  return 0;
}