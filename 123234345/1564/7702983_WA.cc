#include<stdio.h>
#include<string.h>
int main()
{
    int sum,n;
    while(scanf("%d%d",&sum,&n),sum)
    {
          int d[101];
          for(int i=0;i<n;i++)
               scanf("%d",&d[i]);
          int flag=0;
          printf("Sums of %d:\n",sum);
          char s[500]={0},pre[500]={0};
          for(int k=0;k<(1<<n);k++)
          {
               int res=0,m=0;
               for(int i=0;i<n;i++)
                    if(k&(1<<i)) m++,res+=d[i];
               int len=0;
               if(res==sum)
               {
                   flag=1;
                   int fir=0;
                   for(int i=0;i<n;i++) if(k&(1<<i))
                   {
                       if(fir) s[len++]='+';
                       fir=1;
                       if(d[i]<10) s[len++]=d[i]+'0';
                       else s[len++]=d[i]/10+'0',s[len++]=d[i]%10+'0';
                       
                   }
                   s[len]=0;
                   if(strcmp(s,pre))
                   {
                        puts(s);
                        strcpy(pre,s);
                   }
               }
          }
          if(!flag) puts("NONE");
    }   
}
