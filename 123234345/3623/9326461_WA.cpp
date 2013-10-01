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
     //printf("%d %d\n",h,t);
     if(h>t) return ;
     if(h==t) {ans[cnt++]=org[h++];return ;}
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
     int k=0,min='Z';
     for(int x=h;x<i;x++) if(org[x]<min)
     {
           min=org[x];
           k=x-h;
     }
     if(min>org[i]) min=org[i],k=i-h;
     if(min>org[j]) min=org[j],k=t-j;
     if(org[i]<=org[j])
     {
            for(int x=0;x<=k;x++)
                ans[cnt++]=org[h++];
     }else 
           for(int x=0;x<=k;x++)
                ans[cnt++]=org[t--];
     solve(h,t);
}
int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
         char s[2];
         scanf("%s",s);
         org[i]=s[0];
    }//org[n]=0;puts(org);
    cnt=0;
    solve(0,n-1);
    disp();
    scanf("%'d");
}
