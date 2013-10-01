#include<iostream>
using namespace std;
char a[1024][2048];
int dfs(int n,int p,int q)
{
    if(n==1)
    {
            a[p][q]='/';
            a[p][q+1]='\\';
            a[p+1][q-1]='/';
            a[p+1][q+2]='\\';
            a[p+1][q]='_';
            a[p+1][q+1]='_';
    }
    else
    {   
        int t=1<<(n-1);
        dfs(n-1,p+t,q-t);
        dfs(n-1,p+t,q+t);
        dfs(n-1,p,q);
    }
}
int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {          
               int p=1<<n;
               int q=1<<(n+1);
               for(int i=0;i<p;i++)
               for(int j=0;j<q;j++)
               a[i][j]=' '; 
               dfs(n,0,p-1);
               for(int i=0;i<p;i++)
               {
               for(int j=0;j<=p+i;j++)
               cout<<a[i][j];
               cout<<endl; 
               } 
               cout<<endl;
               
               cin>>n;
    }
    return 0;
} 
