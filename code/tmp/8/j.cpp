#include <iostream>
#include <cstdio>
#include <cstring>
const char q[] = "`~!@#$%^&*()\n qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890-=_+[]\\{}|;':\",./<>?";
const char d[] = "`~!@#$%^&*()\n ',.pyfgcrlaoeuidhtn;qjkxbm\"<>PYFGCRLAOEUIDHTN:QJKXBM1234567890[]{}/=\\?+|s-S_wvzWVZ";

int main()
{
  char ch;
  int len = strlen(q);
  while ((ch = getchar()) != EOF) {
    int i;
    for (i = 0; i < len; i++) {
      if (ch == q[i])
        break;
    }
    putchar(d[i]);
  }
  return 0;
}
