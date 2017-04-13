#include<stdio.h>
using namespace std;
int t,y,day,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&y);
		int yy = 1900;
		day = 2;
		while (yy != y) {
			yy++;
			if (!(yy % 400) || (!(yy % 4) && (yy % 100))) {
				day += 366;
			} else {
				day += 365;
			}
			day %= 7;
		}
		switch(day)
		{
			case 0:day=6;break;
			case 1:day=9;break;
			case 2:day=6;break;
			case 3:day=5;break;
			case 4:day=5;break;
			case 5:day=5;break;
			case 6:day=5;break;
		}
		printf("%d\n",day);
	 }
	return 0;
 }
