#include<stdio.h>
#include<string.h>
__int64 s[4][10];
__int64 a[15][4];
void init()
{
     // construct DFA
     s[0][6]=1;
     s[1][6]=2;
     s[2][6]=3;
     for(int i=0;i<10;i++) s[3][i]=3;
     //DP cal a
     a[0][3]=1;
     for(int i=1;i<15;i++)
          for(int j=0;j<4;j++)
              for(int k=0;k<10;k++)
                   a[i][j]+=a[i-1][s[j][k]];
     
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int n,len;
         scanf("%d",&n);
         for(len=0;a[len][0]<=n;len++) ;
         __int64 state=0,num=0;
         for(int i=len-1;i>=0;i--)
         {
              int j=0;
              for(;j<10;j++)
                 if(a[i][s[state][j]]<n) n-=a[i][s[state][j]];
                 else break;
              num=num*10+j;
              state=s[state][j];
         }
         printf("%I64d\n",num);
    }
}
