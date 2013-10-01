#include<stdio.h>
#include<stdlib.h>
const int N=11;
int a[11],b[11];
int main()
{
    int n1,n2;
    while(scanf("%d%d",&n1,&n2),n1&&n2)
    {
          for(int i=0;i<n1;i++)
                scanf("%d",&a[i]);
          for(int j=0;j<n2;j++)
                scanf("%d",&b[j]);
          int ans=0;
          for(int i=0;i<n1;i++)
          {
              for(int j=0;j<n2;j++)
                  if(a[i]==b[j])
                         {b[j]=0;break;}
          }
          for(int i=0;i<n1;i++)
              ans+=a[i];
          for(int j=0;j<n2;j++)
              ans+=b[j];
          printf("%d\n",ans);
    }
}
