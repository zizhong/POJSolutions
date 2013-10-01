#include<cstdio>
#include<cstring>
char w[400010];
int fail[400010]={-1};
bool v[4000010];
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
         memset(v,0,sizeof(v));
         kmp();
         int n=strlen(w),j=n;
         while(j>0) v[j]=1,j=fail[j-1]+1;
         int fir=0;
         for(int i=1;i<=n;i++) if(v[i])
         {
              if(fir)putchar(' ');fir=1;
              printf("%d",i);
         }
         puts("");
    }
}
