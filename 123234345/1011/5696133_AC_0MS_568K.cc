#include<stdio.h>
#include<stdlib.h>
int n,s[64],used[64],st;
int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int dfs(int m,int left,int len)
{
    if(m==0&&left==0) return 1;
    int i;
    if(left==0) i=0,left=len;
    else i=st+1;
    for(int pre=-1;i<n;++i)
    {
        if(s[i]==pre||used[i]||left<s[i]) continue;
        pre=s[i],st=i,used[i]=1;
        if(dfs(m-1,left-s[i],len)) return 1;
        used[i]=0;
        if(left==len||left==s[i]) break;
    }
    return 0;
}
int main()
{
    while(scanf("%d",&n)&&n)
    {
         int sum=0;
         for(int i=0;i<n;i++)
         {
             scanf("%d",&s[i]);
             sum+=s[i];
             used[i]=0;
         }
         qsort(s,n,sizeof(int),cmp);
         for(int i=s[0];i<=sum;i++)            
            if(sum%i==0&&dfs(n,0,i)) {printf("%d\n",i);break;}
    }
}
