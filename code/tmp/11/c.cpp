#include <bist/stdc++.h>
int cnt;
string trs(int x)
{

}
string add(string a, string b)
{
  for (int i = 0; i < a.size(); i++) {
    
  }
}
int main()
{
  int a, b;
  while (~scanf("%d %d", &a, &b)) {
    cnt = 0;
    string sum = trs(a);
    for (int i = a + 1; i <= b; i++) {
      sum = add(sum, trs(i));
    }
    printf("%d\n", cnt);
  }
}