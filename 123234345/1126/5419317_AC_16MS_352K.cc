#include "stdio.h"
#include "string.h"
int IsCorrect(char *s,int start,int end)
{
	int i;
	if(end==start)
	{
		if(s[start]<='z'&&s[start]>='p')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(s[start]=='N'&&IsCorrect(s,start+1,end))
	{
		return 1;
	}
	else if(s[start]<='E'&&s[start]>='C'||s[start]=='I')
	{
		for(i=1;i<end-start;i++)
		{
			if(IsCorrect(s,start+1,start+i)&&IsCorrect(s,start+i+1,end))
			{return 1;}
		}
		 return 0;
	}
	else
	{
		return 0;
	}

}
int main()
{
	int len,i;
	char s[260];
	while((scanf("%s",s))!=EOF)
	{
		len=strlen(s);
		i=IsCorrect(s,0,len-1);
		if(i==1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
