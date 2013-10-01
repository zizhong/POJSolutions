#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int inf=0x3fffffff,N=110;
int f[N][N],len;
string ans[N][N];
char s[N];
char match[128];
void dp()
{
     len=strlen(s);
     for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
        {
            if(i<=j)f[i][j]=inf;
            else f[i][j]=0;
            ans[i][j]="";
        }
     for(int l=1;l<=len;l++)
     {
          if(l==1)
          {
               for(int i=0;i<len;i++)
               {
                    f[i][i]=1;
                    switch (s[i])
                    {
                          case '(':
                          case ')':ans[i][i]="()";break;
                          case '[':
                          case ']':ans[i][i]="[]";break;
                    }
               }
               continue; 
          }   
          for(int i=0;i<len-l+1;i++)
          {
               int j=i+l-1;
               if(s[j]==match[s[i]]&&f[i][j]>f[i+1][j-1])
               {
                    f[i][j]=f[i+1][j-1];
                    ans[i][j]=s[i]+ans[i+1][j-1]+s[j];
               }
               for(int k=i;k<j;k++)
               {
                       if(f[i][j]>f[i][k]+f[k+1][j])
                       {
                            f[i][j]=f[i][k]+f[k+1][j];
                            ans[i][j]=ans[i][k]+ans[k+1][j];
                       }
               }
          }
     }
}
int main()
{
    match['(']=')';
    match['[']=']';
    while(gets(s)!=NULL)
    {
        dp();
        if(len>0) cout<<ans[0][len-1]<<endl;
        else puts("");
    }
}
