#include<stdio.h>
#include<string.h>
int main()
{
	int n,a[200]={0},len,count[200]={0},k,temp,point[200]={0},t;
	char str[201]={0},str1[201]={0};
	scanf("%d",&n);
	while(n!=0)
	{
		for(int i=0;i<=n-1;i++)
			scanf("%d",&a[i]);
		memset(count,0,sizeof(count));
		for(int i=0;i<=n-1;i++)
		{
			temp=i;
			while(1)
			{
				temp=a[temp]-1;
				count[i]++;
				if(temp==i)
					break;
			}
		}
		scanf("%d",&k);
		getchar();
		gets(str);
		while(1)
		{
			len=strlen(str);
			if(n>len)
			{
				for(int i=len;i<n;i++)
					str[i]=' ';
				str[n]='\0';
			}
			strcpy(str1,str);
			for(int i=0;i<=n-1;i++)
			{
				t=k%count[i];
				temp=i;
				for(int j=1;j<=t;j++)
					temp=a[temp]-1;
				str[temp]=str1[i];
			}
			printf("%s\n",str);	
			scanf("%d",&k);
			if(k==0)
			{
				printf("\n");
				break;
			}
			getchar();
			gets(str);
		}
		memset(point,0,sizeof(point));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
	}
	return 0;
}
