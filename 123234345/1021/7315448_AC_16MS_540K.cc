#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node
{
       int x,y;
}g1[101*101],g2[101*101];
int w,h,n;
int cnt1[10001],n1;
int cnt2[10001],n2;
int map1[101][101],map2[101][101];
struct Dim
{
       int ic,id;
} dim1[100*101],dim2[100*101];
int nn=0;
void dfs1(int x,int y)
{
     if(x<0||x>=w||y<0||y>=h) return ;
     if(map1[x][y]==0||cnt1[map1[x][y]]) return ;
     cnt1[map1[x][y]]=n1;
     dfs1(x-1,y),dfs1(x+1,y),dfs1(x,y+1),dfs1(x,y-1);
}
void dfs2(int x,int y)
{
     if(x<0||x>=w||y<0||y>=h) return ;
     if(map2[x][y]==0||cnt2[map2[x][y]]) return ;
     cnt2[map2[x][y]]=n2;
     dfs2(x-1,y),dfs2(x+1,y),dfs2(x,y+1),dfs2(x,y-1);
}
int cmp(const void *a,const void *b)
{
    return ((Dim *)a)->ic - ((Dim *)b)->ic; 
}
int Dis2(Node p1,Node p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
struct BC
{
     int num,key;
}bc1[10000],bc2[10000];
int  solve()
{
     //dfs计数 
     memset(cnt1,0,sizeof(cnt1));
     memset(cnt2,0,sizeof(cnt2));
     n1=n2=0;
     for(int i=1;i<=n;i++)
         if(cnt1[i]==0)
         {
             n1++;
             dfs1(g1[i].x,g1[i].y);
         }
     for(int i=1;i<=n;i++)
        if(cnt2[i]==0)
        {
             n2++;
             dfs2(g2[i].x,g2[i].y);
        }
     //基本比较
     if(n1!=n2) return 0;
     for(int i=1;i<=n;i++)
     {
          dim1[i].ic=cnt1[i],dim1[i].id=i;
          dim2[i].ic=cnt2[i],dim2[i].id=i;
     }
     qsort(dim1+1,n,sizeof(dim1[1]),cmp);
     qsort(dim2+1,n,sizeof(dim2[1]),cmp);
     //块的距离和  
     int nn1=0,nn2=0;
     int v1[10001]={0},v2[10001]={0};
     for(int i=1;i<=n;)
     {
          int k=i;
          while(k<=n&&dim1[i].ic==dim1[k].ic)
               k++;
          if(k-i<2) {i=k;continue;}
          bc1[nn1].num=k-i;
          int key=0;
          for(int h1=i;h1<k;h1++)
             for(int h2=h1+1;h2<k;h2++)
                 key+= Dis2(g1[dim1[h1].id],g1[dim1[h2].id]);
          bc1[nn1].key=key;
          nn1++;
          i=k;
     }
     for(int i=1;i<=n;)
     {
          int k=i;
          while(k<=n&&dim2[i].ic==dim2[k].ic)
               k++;
          if(k-i<2) {i=k;continue;}
          bc2[nn2].num=k-i;
          int key=0;
          for(int h1=i;h1<k;h1++)
             for(int h2=h1+1;h2<k;h2++)
                 key+= Dis2(g2[dim2[h1].id],g2[dim2[h2].id]);
          bc2[nn2].key=key;
          nn2++;
          i=k;
     }
     if(nn1!=nn2) return 0;
     for(int i=0;i<nn1;i++)
     {
          int flag=0;
          for(int j=0;j<nn2;j++)
             if(bc1[i].num==bc2[j].num&&v2[j]==0&&bc1[i].key==bc2[j].key)
             {
                  v2[j]=1;
                  flag=1;
                  break;
             }
          if(flag==0) return 0;
     }
     return 1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         memset(map1,0,sizeof(map1));
         memset(map2,0,sizeof(map2));
         scanf("%d%d%d",&w,&h,&n);
         for(int i=1;i<=n;i++)
         {
              scanf("%d%d",&g1[i].x,&g1[i].y);
              map1[g1[i].x][g1[i].y]=i;
         }
         for(int i=1;i<=n;i++)
         {
              scanf("%d%d",&g2[i].x,&g2[i].y);
              map2[g2[i].x][g2[i].y]=i;
         }
         puts(solve()?"YES":"NO");
    }
}
