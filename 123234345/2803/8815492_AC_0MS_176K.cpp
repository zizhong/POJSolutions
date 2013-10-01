#include<stdio.h>
#include<string.h>
const int N=110;
char s[N];
int len1[2][5]={{4,4,3,2,2},{2,3,3,1,4}};
char pre[5][2][16] =
{
     {"anti","against "},
     {"post","after "},
     {"pre","before "},
     {"re"," again"},
     {"un","not "}
};
char post[5][2][36] =
{
     {"er","one who "},
     {"ing","to actively "},
     {"ize","change into "},
     {"s","multiple instances of "},
     {"tion","the process of "}
};
int f1,f2;
void deal(int h,int t)
{
     if(f1==0)
     for(int i=0;i<5;i++)
     {
         if(t-h>=len1[0][i] && strncmp(s+h,pre[i][0],len1[0][i])==0)
         {
              f1=1;
              if(i==3)
              {
                   deal(h+2,t);
                   printf("%s",pre[i][1]);
              }
              else
              {
                  printf("%s",pre[i][1]);
                  deal(h+len1[0][i],t);
              }
              return ;
         }
     }
     if(f2==0)
     for(int i=0;i<5;i++)
     {
         if(t-h>=len1[1][i] && strncmp(s+t-len1[1][i],post[i][0],len1[1][i])==0)
         {
              f2=1;
              printf("%s",post[i][1]);
              deal(h,t-len1[1][i]);
              if(i==0) printf("s");
              if(i==4) printf("ing");
              return ;
         }
     }
     for(int i=h;i<t;i++) putchar(s[i]);
     return ;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
          for(int i=0;i<n;i++)
          {
              f1=f2=0;
              scanf("%s",s);
              deal(0,strlen(s));
              puts("");
          }
    }
}
