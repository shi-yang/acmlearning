#include<iostream>
using namespace std;
int main()
{
  string str;
  cin >> str;
  char tmp = str[0], fre = str[0], ed;
  int cnt = 1;
  for (int i = 1; i < str.size(); i++) {
    if (str[i] == tmp) {
      cnt++;
    } else {
      tmp = str[i];
      cnt = 1;
    }
    if (cnt == 2) {
      if (i <= str.size() - 2) {
        int k = 1;
        while (str[i] == tmp || str[i] == str[i + 1]) {
          if (str[i] < 'z') {
            str[i] = 'a' + k;
            k++;
          } else {
            str[i] = 'a';
          }
        }
      } else {
        int k = 1;
        while (str[i] == tmp) {
          if (str[i] < 'z') {
            str[i] = 'a' + k;
            k++;
          } else {
            str[i] = 'a';
          }
        }
      }
      cnt = 1;
      tmp = str[i];
    }
  }
  cout << str << endl;
  return 0;
}
