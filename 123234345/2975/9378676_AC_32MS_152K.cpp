#include<cstdio>
int num[1005];
int main()
{
	int n,temp,temp2,cnt,i;
	while(scanf("%d",&n)&&n)
	{
		temp=0,cnt=0;;
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			temp^=num[i];
		}
		if(temp!=0)
		{
			for(i=0;i<n;i++)
			{
				temp2=temp^num[i];
				if(temp2<num[i]) cnt++;
			}
		}
		printf("%d\n",cnt);
	}
}
