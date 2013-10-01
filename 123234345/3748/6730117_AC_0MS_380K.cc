#include <stdio.h>

#define setbit(x,y) x|=(1<<(y))
#define clrbit(x,y) x&=~(1<<(y))
int main()
{
	int r, x, y;
	scanf("%x,%d,%d", &r, &x, &y);
	clrbit(r, x);
	setbit(r, y);
	setbit(r, y - 1);
	clrbit(r, y - 2);
	printf("%x\n", r);
	return 0;
}
