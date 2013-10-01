#include<stdio.h>
int  min,max,temp;
bool swin;
void check()
{
	if(swin)printf("Stan wins\n");
	else printf("Ollie wins\n");
}
int main()
{
	while(1)
	{
		scanf("%d%d",&max,&min);
		if(min==0&&max==0)break;
		if(max<min){temp=max;max=min;min=temp;}
		swin=1;
		while(1)
		{
			if(max/min>1){check();break;}
			temp=max%min,max=min,min=temp;
			if(min==0){check();break;}
			swin^=1;
		}
	}
}