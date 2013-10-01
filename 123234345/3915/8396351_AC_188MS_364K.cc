#include<stdio.h>
#include<string.h>
char str[5][6];
int r;
int Best,sol;
int v[19];
char s[5][6];
int x;
struct Node
{
       int p,num;
       char s[4];
}re[16];
void deal()
{
     int find[3]={0};
     for(int i=0;i<3;i++)
     {
         for(int j=0;j<3;j++)
            if(s[3][j]==str[4][i])
               find[i]=1;
     }
     if(find[1]&&find[2]&&find[0]) return ;
     int k;
     for(k=1;k<=r;k++)
     {
          int ans=0;
          if(re[k].p==x) continue;
          for(int h=0;h<3;h++)
             for(int j=0;j<5;j++)
             {
                int tar=re[k].p;
                if(tar>x) tar--;
                if(re[k].s[h]==s[tar][j])
                   ans++;
             }
          if(ans!=re[k].num)
          {
               break;
          }
     }
     if(sol<k) sol=k;
}
void dfs(int st,int n1,int n2,int n3)
{
     if(sol>Best) return ;
     if(v[st])
     {
           dfs(st+1,n1,n2,n3);
           return ;
     }
     if(n1==5&&n2==5&&n3==3)
     {
           if(sol<Best) 
               deal();
           return ;
     }
     if(n1<5)
     {
          s[1][n1]=st+'A';
          dfs(st+1,n1+1,n2,n3);
     }
     if(n2<5)
     {
          s[2][n2]=st+'A';
          dfs(st+1,n1,n2+1,n3);
     }
     if(n3<3)
     {
          s[3][n3]=st+'A';
          dfs(st+1,n1,n2,n3+1);
     }
}
void solve()
{
     for(int i=0;i<19;i++)
         v[i]=0;
     for(int i=0;str[x][i];i++)
         v[str[x][i]-'A']=1;
     sol=0;
     dfs(0,0,0,0);
}
int main()
{   
    while(scanf("%d",&r),r)
    {
         scanf("%s%s%s%s",str[1],str[2],str[3],str[4]);
         Best=r+1;
         for(int i=1;i<=r;i++)
             scanf("%d%s%d",&re[i].p,re[i].s,&re[i].num);
         for(x=1;x<=3;x++)
         {
              solve();
              if(sol<Best)
                 Best=sol;
         }
         if(Best==r+1) puts("?");
         else printf("%d\n",Best);
    }
}
