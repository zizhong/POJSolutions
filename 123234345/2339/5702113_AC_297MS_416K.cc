#include<stdio.h>
#include<string.h>
int s[2][105][105];
bool near(int i,int j,int k,char c)
{
     return s[i][j-1][k]==c||s[i][j][k-1]==c||s[i][j+1][k]==c||s[i][j][k+1]==c;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int r,c,n;
        scanf("%d%d%d",&r,&c,&n);
        memset(s,'*',sizeof(s));
        getchar();
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                char c=getchar();
                while(c!='R'&&c!='P'&&c!='S') c=getchar();
                s[0][i][j]=c;
            }
        }
        for(int i=1;i<=n;i++)
        {
             for(int j=1;j<=r;j++)
               for(int k=1;k<=c;k++)
                 {
                       if(s[(i+1)%2][j][k]=='R'&&near((i+1)%2,j,k,'P'))   s[i%2][j][k]='P';
                       else if(s[(i+1)%2][j][k]=='P'&&near((i+1)%2,j,k,'S'))   s[i%2][j][k]='S';
                       else if(s[(i+1)%2][j][k]=='S'&&near((i+1)%2,j,k,'R'))   s[i%2][j][k]='R';
                       else s[i%2][j][k]=s[(i+1)%2][j][k];
                 }
        }
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
                putchar(s[n%2][i][j]);
            puts("");
        }
        if(t) puts("");
    }
}
