#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
  char s1[12], s2[12];
  char weighing[5];
  int n, flag[12];
  cin >> n;
  while (n--) {
  memset(flag, 0, sizeof(flag));
  for (int i = 0; i < 3; i++) {
    cin >> s1 >> s2 >> weighing;
    int len = strlen(s1);
    if (strcmp(weighing, "even") == 0) {
      for (int i = 0; i < len; i++) {
        flag[s1[i] - 'A'] = 10;
        flag[s2[i] - 'A'] = 10;
      }
    } else if (strcmp(weighing, "up") == 0) {
      for (int i = 0; i < len; i++) {
        if (flag[s1[i] - 'A'] != 10)
          ++flag[s1[i] - 'A'];
        if (flag[s2[i] - 'A'] != 10)
          --flag[s2[i] - 'A'];
      }
    } else {
      for (int i = 0; i < len; i++) {
        if (flag[s1[i] - 'A'] != 10)
          --flag[s1[i] - 'A'];
        if (flag[s2[i] - 'A'] != 10)
          ++flag[s2[i] - 'A'];
      }
    }
  }
  int max = 0, index = 0;
  for (int i = 0; i < 12; i++) {
    if (flag[i] == 10)
      continue;
    if (max <= abs((float)flag[i])) {
      max = abs((float)flag[i]);
      index = i;
    }
  }
  if (flag[index] > 0)
    printf("%c is the counterfeit coin and it is heavy.\n", index + 'A');
  else
    printf("%c is the counterfeit coin and it is light.\n", index + 'A');
  }
  return 0;
}