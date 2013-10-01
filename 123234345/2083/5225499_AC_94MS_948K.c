#include<stdio.h>
char a[730][730];
int h[8]={0,1,3,9,27,81,243,729};
void dfs(int n,int i,int j)
{
     if(n==1)
     {
        a[i][j]='X';
        return ;
     }
     dfs(n-1,i-h[n-1],j-h[n-1]);
     dfs(n-1,i+h[n-1],j-h[n-1]);
     dfs(n-1,i-h[n-1],j+h[n-1]);
     dfs(n-1,i+h[n-1],j+h[n-1]);
     dfs(n-1,i,j);
}
int main()
{
    int n,i,j;    
    while(scanf("%d",&n)&&n!=-1)
    {
       memset(a,' ',sizeof(a));
       dfs(n,(h[n]+1)*0.5-1,(h[n]+1)*0.5-1);
       for(i=0;i<h[n];i++)
       {
          for(j=h[n];j>=0&&a[i][j]!='X';j--)
              a[i][j]='\0';
       }
       for(i=0;i<h[n];i++)
           printf("%s\n",a[i]);
       printf("-\n");
    }
}
