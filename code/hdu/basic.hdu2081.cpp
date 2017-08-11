#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  while (n--) {
    string str;
    cin >> str;
    cout << 6;
    for (int i = 6; i < 11; i++) {
      cout << str[i];
    }
    cout << endl;
  }
  return 0;
}
