#include<stdio.h>
char l[2000000001];
int main()
{
    int len,m;
    while(scanf("%d%d",&len,&m)&&(len!=0))
    {
        memset(l,'1',sizeof(l));
        int i,j,end,begin,left=0;
        for(i=0;i<m;i++)
        {
           scanf("%d%d",&begin,&end);
           for(j=begin;j<=end;j++)
              l[j]='0';              
        }
       for(i=0;i<=len;i++)
          if(l[i]=='1') left++;
       printf("%d\n",left);
    }
}
