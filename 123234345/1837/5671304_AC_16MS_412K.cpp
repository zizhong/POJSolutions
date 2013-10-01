#include<stdio.h>
const int N=21;
const int M=4501;
const int Mid=M>>1;
int loc[N],w[N],state[N][M];
int main()
{
    int C,G;
    scanf("%d%d",&C,&G);
    for(int i=1;i<=C;i++)
        scanf("%d",&loc[i]);
    for(int i=1;i<=G;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=C;i++)
         state[1][Mid+loc[i]*w[1]]=1;
    for(int i=2;i<=G;i++)
       for(int j=1;j<=C;j++)
       {
          for(int k=0;k<M;k++)
          {
               int pw=k-loc[j]*w[i];
               if(pw>=0||state[i-1][pw]) state[i][k]+=state[i-1][pw];
          }
       }
    printf("%d\n",state[G][Mid]);
}
