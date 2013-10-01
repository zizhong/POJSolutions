#include<stdio.h>
#include<string.h>
char a[10][23][12];
char m[23][128];
int n;
char s[12];
int r,c,len;
void table()
{
     memset(a,' ',sizeof(a));
     for(int i=0;i<=9;i++)
     {
         for(int j=0;j<r;j++)
         {
             if(j==0||j==n+1||j==r-1) continue;
             if(j<n+1)
             {
                 if(i!=1&&i!=2&&i!=3&&i!=7) a[i][j][0]='|';
                 if(i!=5&&i!=6) a[i][j][c-1]='|';
             }
             if(j>n+1)
             {
                 if(i!=1&&i!=3&&i!=4&&i!=5&&i!=7&&i!=9) a[i][j][0]='|';
                 if(i!=2) a[i][j][c-1]='|';
             }
         }
         if(i==1) continue;
         for(int j=1;j<c-1;j++)
         {
              if(i!=4) a[i][0][j]='-';
              if(i!=0&&i!=7) a[i][n+1][j]='-';
              if(i!=4&&i!=7) a[i][r-1][j]='-';
         }
     }
}
void link()
{
     len=strlen(s);
     memset(m,' ',sizeof(m));
     for(int i=0;i<len;i++)
     {
          int ki=s[i]-'0';
          for(int j=0;j<r;j++)
             for(int k=0;k<c;k++)
                 m[j][k+i*(c+1)]=a[ki][j][k];
     }
}
void print()
{
     for(int i=0;i<r;i++)
     {
         int j=127;
         while(m[i][j]==' ') m[i][j]='\0',--j;
     }
     for(int i=0;i<r;i++)
     {
        for(int j=0;j<len*(c+1)-1;j++)
        {
          if(m[i][j])
           printf("%c",m[i][j]);
        }
       printf("\n");
    }
    printf("\n");
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%s",&n,s)&&n)
    {
        r=3+2*n;
        c=n+2; 
        table();
        link();
        print();
    }
}
