#include<stdio.h>
const int N=1001;
int tree[N];
int f[N][31][2];
int _max(int a,int b){return a>b?a:b;}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,w;
    scanf("%d%d",&T,&w);
    for(int i=1;i<=T;i++) scanf("%d",&tree[i]);
    f[0][0][1]=-1;
    for(int i=0;i<T;i++)
    {
         f[i+1][0][0]=f[i][0][0]+(tree[i+1]==1);
         for(int j=0;j<w;j++)
         {
              f[i+1][j+1][1]=_max(f[i][j][0]+(tree[i+1]==2),f[i][j+1][1]+(tree[i+1]==2));
              f[i+1][j+1][0]=_max(f[i][j][1]+(tree[i+1]==1),f[i][j+1][0]+(tree[i+1]==1));
         }         
    }
    /*for(int i=0;i<T;i++) 
       for(int j=i+1;j<=T;j++)
       {
           int a=f[][][]
       }*/
    int ans=0;
    for(int i=0;i<=w;i++) ans=_max(ans,_max(f[T][i][0],f[T][i][1]));
    printf("%d\n",ans);
    /*for(int i=1;i<=T;i++)
    {
         for(int j=0;j<=w;j++)
             printf("(%3d,%3d)   ",f[i][j][0],f[i][j][1]);
         printf("\n");
    }*/
}
