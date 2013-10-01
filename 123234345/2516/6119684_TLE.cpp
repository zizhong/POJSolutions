#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=50,INF=1000000000,MAX=100000;
bool _vix[N*3],_viy[N*3];
int _lny[N*3],_lax[N*3],_lay[N*3],_sla[N*3];
bool km_find(int i,int y,int g[][N*3])
{
     _vix[i]=true;
     for(int j=0;j<y;j++)
     {
          if(_viy[j]) continue;
          int t=_lax[i]+_lay[j]-g[i][j];
          if(t){if(t<_sla[j]) _sla[j]=t;}
          else
          {
              _viy[j]=true;
              if(_lny[j]<0||km_find(_lny[j],y,g))
              {
                   _lny[j]=i;
                   return true;
              }
          }
     }
     return false;
}
int KM(int x,int y,int g[][N*3])
{
    int i,j,end=x>y?y:x;
    memset(_lny,-1,sizeof(_lny));
    memset(_lay,0,sizeof(_lay));
    for(i=0;i<x;i++)
        _lax[i]=*max_element(g[i],g[i]+y);
    for(i=0;i<end;i++)
    {
       fill_n(_sla,y,INF);
       while(true)
       {
           memset(_vix,0,sizeof(_vix));
           memset(_viy,0,sizeof(_viy));
           if(km_find(i,y,g)) break;
           int d=INF;
           for(j=0;j<y;j++)
              if(!_viy[j]&&_sla[j]<d) d=_sla[j];
           for(j=0;j<x;j++)
              if(_vix[j]) _lax[j]-=d;
           for(j=0;j<y;j++)
              if(_viy[j]) _lay[j]+=d;
              else _sla[j]=-d;
       }
    }
    int res=0;
    for(i=0;i<y;++i)
        if(!(_lny[i]<0))
           res+=g[_lny[i]][i];
    return res;
}
int _cos[N][N][N],_g[N*3][N*3],_ned[N][N],_sup[N][N];
int _inx[N][3],_iny[N][3],_sum[N];
int Sol(int n,int m,int p)
{
    int i,j,k,l,end,x=0,y=0;
    for(i=0;i<n;i++)
       for(end=j=0;j<_ned[i][p];++j)
           _inx[i][end++]=x++;
    for(i=0;i<m;i++)
       for(end=j=0;j<_sup[i][p];++j)
          _iny[i][end++]=y++;
    for(i=0;i<x;i++) for(j=0;j<y;j++)
        _g[i][j]=0;
    for(i=0;i<n;i++)
       for(j=0;j<_ned[i][p];++j)
          for(k=0;k<m;++k)
             for(l=0;l<_sup[k][p];++l)
                 _g[_inx[i][j]][_iny[k][l]]=_cos[p][i][k];
    for(i=0;i<x;i++)
       for(j=0;j<y;j++)
          _g[i][j]=MAX-_g[i][j];
    return MAX*x-KM(x,y,_g);
}
int main()
{
    int n,m,p,i,j,k;
    while(scanf("%d%d%d",&n,&m,&p),n||m||p)
    {
         memset(_sum,0,sizeof(_sum));
         for(i=0;i<n;i++)
            for(j=0;j<p;j++)
            {
                 scanf("%d",&_ned[i][j]);
                 _sum[j]+=_ned[i][j];
            }
         for(i=0;i<m;i++)
             for(j=0;j<p;j++)
             {
                 scanf("%d",&_sup[i][j]);
                 _sum[j]-=_sup[i][j];
             }
          for(i=0;i<p;i++)
             for(j=0;j<n;j++)
                 for(k=0;k<m;k++)
                     scanf("%d",&_cos[i][j][k]);
          for(i=0;i<p;i++)
              if(_sum[i]>0) break;
          if(i<p) puts("-1");
          else
          {
              int ans=0;
              for(i=0;i<p;i++)
                  ans+=Sol(n,m,i);
              printf("%d\n",ans);
          }
    }
}
