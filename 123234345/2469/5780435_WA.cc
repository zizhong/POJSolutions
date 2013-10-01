#include<stdio.h>
#include<string.h>
char s[53][50];
int c[101][53];
void table()
{
     char se[5][10]={"Clubs","Diamonds","Hearts","Spades"};
     char num[15][10]={"","","2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
     for(int i=0;i<4;i++)
         for(int j=2;j<=14;j++)
                 sprintf(s[i*13+j-1],"%s of %s",num[j],se[i]);
     for(int i=1;i<=52;i++) c[0][i]=i;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    table();
    int nt;
    scanf("%d",&nt);
    for(int i=1;i<=nt;i++)
       for(int j=1;j<=52;j++)
          scanf("%d",&c[i][j]);
    for(int i=1;i<=nt;i++)
       for(int j=1;j<=52;j++)
          c[i][j]=c[i-1][c[i][j]];
    int k;
    while(scanf("%d",&k)!=EOF)
    {
         for(int i=1;i<=52;i++)
             printf("%s\n",s[c[k][i]]);
         printf("\n");
    }
}
