#include <bits/stdc++.h>
using namespace std;
string str[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
  "-.", "---", ".--.", "--.-", ".-.","...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---",
  "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "..--..", "-..-.", "-.--.-", "-.--.-", "-....-", ".-.-.-"};
char le[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', 
  '4', '5', '6', '7', '8', '9', '0', '?', '/', '(', ')', '-', '.'};
string in[30];
int main()
{
  int t;
  int kas = 1;
  scanf("%d", &t);
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> in[i];
    string tt, ans;
    for (int i = 0; i < n; i++) {
      if (i)
        ans += ".......";
      string tmp = in[i];
      for (int j = 0; j < tmp.size(); j++) {
        if (j)
          ans += "...";
        int k = 0;
        while (le[k] != tolower(tmp[j]))
          k++;
        for (int qq = 0; qq < str[k].size(); qq++) {
          if (qq)
            ans += '.';
          if (str[k][qq] == '.')
            ans += '=';
          else if (str[k][qq] == '-')
            ans += "===";
        }
      }
    }
    cout << "Case #" << kas << ": " << ans << endl; 
    kas++;
  }
  return 0;
}