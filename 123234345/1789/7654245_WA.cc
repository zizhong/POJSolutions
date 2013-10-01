#include<stdio.h>
const int N=2001;
char type[N][8];
int caldif(int i,int j)
{
    int ans=0;
    for(int k=0;type[i][k];k++)
       if(type[i][k]!=type[j][k])
            ans++;
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         gets(type[0]);
         for(int i=0;i<n;i++)
            gets(type[i]);
         int ans=0;
         for(int i=1;i<n;i++)
         {
             int min=7;
             for(int j=0;j<n;j++) if(j!=i)
             {
                  int num=caldif(j,i);
                  if(num<min) min=num;
             }
             ans+=min;
         }
         printf("The highest possible quality is 1/%d.\n",ans);
    }
}
