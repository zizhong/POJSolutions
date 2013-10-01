#include<stdio.h>
const int N=11; 
char mine[N][N],touch[N][N];
int d[8][2]={{-1,-1},{-1,0,},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
        gets(mine[i]);
    for(int i=0;i<n;i++)
        gets(touch[i]);
    int lose=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(mine[i][j]=='*'&&touch[i][j]=='x') lose=1;
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            {
                 if(mine[i][j]=='*'&&lose) putchar('*');
                 else if(mine[i][j]=='*'&&lose==0) putchar('.');
                 else if(mine[i][j]=='.'&&touch[i][j]=='x')
                 {
                      int m=0;
                      for(int k=0;k<8;k++)
                         if(i+d[k][0]>=0&&i+d[k][0]<n&&j+d[k][1]>=0&&j+d[k][1]<n) m+=(mine[i+d[k][0]][j+d[k][1]]=='*');
                      putchar(m+'0');
                 }
                 else putchar('.');                 
            }  
            puts("");          
    }
}
