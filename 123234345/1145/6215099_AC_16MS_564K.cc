#include<stdio.h>
const int N=1000000;
int nn,tree[N],end[N],M=0;
void dfs(int i)
{
     char c;
     if(i&1) while((c=getchar())!='(')  ;
     while((c=getchar())==' '||c=='\n') ;
     if(c==')'){tree[i]=0,end[i]=nn;return ;}
     int num=c;
     int flag=1;
     if(num=='-') num=0,flag=-1;
     else num=c-'0';
     while(c=getchar())
     {
         if(c==' '||c=='\n') continue;
         if(c=='(') break;
         num=num*10+c-'0';
     }
     tree[i]=num*flag;
     dfs(i*2);
     dfs(i*2+1);
     if(M<i*2+1) M=i*2+1;
     while((c=getchar())!=')') ;
}
int main()
{
    int num;
    while(scanf("%d",&num)!=EOF)
    {
         M=0,nn++;
         dfs(1);
         for(int i=2;i<=M;i++) tree[i]+=tree[i/2];
         int find=0;
         for(int i=1;i<M;i++)
         {
                 if(tree[i]==num&&end[i/2*2]==nn&&end[i/2*2+1]==nn) {find=1;break;}
         }
         puts(find?"yes":"no");
    }
}
