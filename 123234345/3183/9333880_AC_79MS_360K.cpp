#include<cstdio>
#include<cstring>
int h[50010];
int main()
{
  
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    int up=1;
    for(int i=1;i<=n+1;i++)
    {
            if(h[i-1]<=h[i]&&h[i]>=h[i+1])
               printf("%d\n",i);
    }
}
