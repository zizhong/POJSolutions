#include<cstdio>
#include<cstring>
char w[1000010];
int fail[1000010]={-1};
void kmp()
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
    while(gets(w),w[0]!='.')
    {
          kmp();
          int n=strlen(w),t=n-(fail[n-1]+1);
          printf("%d\n",n%t?1:n/t);                        
    }
}
