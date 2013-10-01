
#include<stdio.h>
#include<string.h>
const int N=101;
char str[N][N];
int len[N];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         for(int i=1;i<=n;i++)
         {
              scanf("%s",str[i]);
              len[i]=strlen(str[i]);
         }
         int ans=len[1];
         for(int i=1;i<=n;i++)
            if(ans>len[i]) ans=len[i];
         for(int i=1;i<=n;i++)
             for(int j=i+1;j<=n;j++)
             {
                  int n1=len[i],n2=len[j];
                  if(n1!=n2) continue;
                  while(n1>=0&&n2>=0&&str[i][n1]==str[j][n2]) n1--,n2--;
                  int k=++n1;
                  if(ans>k) ans=k;                  
             }
         if(ans==0) ans++;
         printf("%d\n",ans-1);
    }

}