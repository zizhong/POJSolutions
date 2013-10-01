#include<stdio.h>
const int N=1000001;
int in[N],out[N],hv;
int main()
{
    int T=1;
    int u,v,flag=0;
    while(scanf("%d%d",&u,&v),u>=0)
    {
          int e=0;
          flag=1,hv=0;
          do
          {
              e++;
              if(in[v]!=T&&out[v]!=T) hv++;
              if(in[u]!=T&&out[u]!=T) hv++;
              if(v==u) flag=0;
              if(in[v]!=T) in[v]=T;
              else flag=0;
              if(out[u]!=T) out[u]=T;
              
          }while(scanf("%d%d",&u,&v),u);
          if(e!=hv-1) flag=0;
          printf("Case %d is %sa tree.\n",T++,flag?"":"not ");
    }
}
