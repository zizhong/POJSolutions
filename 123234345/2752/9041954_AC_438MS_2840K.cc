#include<cstdio>
#include<cstring>
char w[400010];
int fail[400010]={-1};
int v[400010],cnt;
int kmp()
{
    int i=0,j;
    int ans=0;
    for (j=1;w[j];j++)
    {
        for (i=fail[j-1];i>=0&&w[i+1]!=w[j];i=fail[i]);
        fail[j]=(w[i+1]==w[j]?i+1:-1);
    }
}

int main()
{
    while(gets(w)!=NULL)
    {
         kmp();
         int n=strlen(w),j=n;
         cnt=0;
         while(j>0) v[cnt++]=j,j=fail[j-1]+1;
         int fir=0;
         for(int i=cnt-1;i>=0;i--)
         {
              if(fir)putchar(' ');fir=1;
              printf("%d",v[i]);
         }
         puts("");
    }
}
