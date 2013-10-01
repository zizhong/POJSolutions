#include<stdio.h>
#include<string.h>
const int N=2001;
int f[N];
int SG(int n)
{
    if(n<0) return 0;
    if(f[n]!=-1) return f[n];
    int v[N]={0};
    for(int i=1;i<=n;i++)
    {
         int a=SG(i-3)^SG(n-i-2);
         if(a<N) v[a]=1;
    }
    int ans=0;
    while(v[ans]) ans++;
    f[n]=ans;
    return ans;
}
int main()
{
    memset(f,-1,sizeof(f));
    int n;
    scanf("%d",&n);
    printf("%d\n",SG(n)?1:2);
}
