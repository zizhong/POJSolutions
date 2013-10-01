#include<stdio.h>
#include<algorithm>
using namespace std;
const int N=6,M=800;
int per[M][N],q[M][N],n,m;
struct Node
{
    int a[3];
}tri[N];
void gen_per()
{
     int a[6]={0,1,2,3,4,5};
     do
     {
         for(int i=0;i<N;i++)
             per[n][i]=a[i];
         n++;
     }while(next_permutation(a,a+6));
     int K=1;
     for(int i=0;i<N;i++) K*=3;
     m=K;
     for(int i=0;i<m;i++)
     {
           int x=i;
           for(int j=0;j<N;j++)
                q[i][j]=x%3,x/=3;
     }
}
int main()
{
    gen_per();
    char over[2];
    do
    {
          for(int i=0;i<N;i++)
              for(int j=0;j<3;j++)
                   scanf("%d",&tri[i].a[j]);
          scanf("%s",over);
          int ans=-1;
          for(int k=0;k<m;k++)
          {
                for(int p=0;p<n;p++)
                {
                      int flag=1;
                      for(int i=0;i<N;i++)
                         if(tri[per[p][i]].a[(q[k][i]+1)%3]!=tri[per[p][(i+1)%N]].a[(q[k][(i+1)%N]+2)%3]) flag=0;
                      if(flag)
                      {
                           int tmp=0;
                           for(int i=0;i<N;i++)
                                tmp+=tri[per[p][i]].a[q[k][i]];
                           if(tmp>ans) ans=tmp;
                      }
                }
          }
          if(ans>=0) printf("%d\n",ans);
          else puts("none");
    }while(over[0]=='*');
}
