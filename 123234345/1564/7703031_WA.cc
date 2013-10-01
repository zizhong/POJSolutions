#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=1<<12;
char str[N][500];
int cmp(const void *a,const void *b)
{
    return strcmp((char *)b,(char *)a);
}
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
          int nn=0;
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
                       s[len++]=d[i];
                   }
                   s[len]=0;
                   if(strcmp(s,pre))
                      strcpy(str[nn++],s),strcpy(pre,s);
               }
          }
          if(nn)
          {
               qsort(str,nn,sizeof(str[0]),cmp);
               for(int i=0;i<nn;i++) if(i==0||strcmp(str[i-1],str[i]))
               {
                    int ln=strlen(str[i]);
                    for(int j=0;j<ln;j++)
                        if(j&1) putchar('+');
                        else putchar(str[i][j]+'0');
                    puts("");
               }
          }
          if(!flag) puts("NONE");
    }   
}
