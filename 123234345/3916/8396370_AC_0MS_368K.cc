#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
          int v[100]={0};
          for(int i=0;i<n;i++)
              scanf("%d",&v[i]);
          for(int i=0;i<n;i++)
             for(int j=i+1;v[i]==v[j];j++)
                    v[j]=0;
          for(int i=0;i<n;i++)
              if(v[i]) printf("%d ",v[i]);
          puts("$");
    }
}
