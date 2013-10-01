#include<stdio.h>
const int N=3001,M=33811;
int p[N];
void init()
{
     int pn=0;
     int flag[M]={0};     
     for(int i=2;i<M;i++)
     {
             if(flag[i]==0)
             {
                  p[++pn]=i;
                  if(pn>=3000) break;
                  int cnt=0;
                  for(int j=i+1;j<M;j++)
                  {
                      if(flag[j]==0) cnt++;
                      if(cnt%i==0) flag[j]=1;
                  }
             }
     }
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n),n) printf("%d\n",p[n]);
}
