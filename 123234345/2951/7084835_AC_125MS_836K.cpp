#include<stdio.h>
#include<string.h>
int f[21][21][401];
int _min(int a,int b){return a>b?b:a;}
int _max(int a,int b){return a>b?a:b;}
int main()
{
    int x1,y1,x2,y2,w,h,d1,d2;
    for(int i=0;i<=20;i++) for(int j=0;j<=20;j++)
        for(int d=0;d<=400;d++)
              f[i][j][d]=10000000;
    for(x1=1;x1<=20;++x1) 
        for(y1=1;y1<=20;++y1)
            f[x1][y1][0]=x1*y1;
    for(x1=1;x1<=20;++x1)
        for(y1=1;y1<=20;++y1)
             for(d1=0;d1<x1*y1;++d1)
             {                    
                    for(x2=1;x2<=20-x1;++x2)
                        for(d2=0;d2<x2*y1;++d2)
                               f[x1+x2][y1][d1+1+d2]=_min(f[x1+x2][y1][d1+d2+1],_max(f[x1][y1][d1],f[x2][y1][d2]));
                    for(y2=1;y2<=20-y1;++y2)
                        for(d2=0;d2<x1*y2;++d2)                        
                               f[x1][y1+y2][d1+d2+1]=_min(f[x1][y1+y2][d1+d2+1],_max(f[x1][y1][d1],f[x1][y2][d2]));
             }
    while(scanf("%d%d%d",&w,&h,&d1),w)
          printf("%d\n",f[w][h][d1-1]);
}
