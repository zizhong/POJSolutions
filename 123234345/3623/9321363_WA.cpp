#include<cstdio>
#include<cstring>
const int N=30010;
char org[N],ans[N];
int cnt,n;
void disp()
{
     for(int i=0;i<cnt/80;i++,puts(""))
         for(int j=0;j<80;j++) putchar(ans[i*80+j]);
     if(cnt%80)
     {
        for(int j=cnt/80*80;j<cnt;j++) putchar(ans[j]);
        puts(""); 
     }
}
void solve(int h,int t)
{
     if(h>t) return ;
     if(h==t)
     {
           ans[cnt++]=org[h];
           return ;
     }
     if(org[h]<org[t])
     {
           ans[cnt++]=org[h++];
           solve(h,t);
           return ;
     }
     if(org[h]>org[t])
     {
           ans[cnt++]=org[t--];
           solve(h,t);
           return ;
     }
     int i=h,j=t;
     while(i<j && org[i]==org[j]) i++,j--;
     if(i<j)
     {
            if(org[i]<org[j])
            {
                 for(int k=h;k<i;k++) ans[cnt++]=org[k];
                 solve(i,t);
                 return ;
            }
            if(org[i]>org[j])
            {
                 for(int k=t;k>j;k--) ans[cnt++]=org[k];
                 solve(h,j);
                 return ;
            }
     }
     //for(int k=h;k<=t;k++) ans[cnt++]=org[k];
     ans[cnt++]=org[h++];
     solve(h,t);
     return ;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
         char s[2];
         scanf("%s",s);
         org[i]=s[0];
    }
    cnt=0;
    solve(0,n-1);
    disp();
    scanf("%'d");
}
