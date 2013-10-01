#include<cstdio>
#include<cstring>
struct Rect
{
       int x1,x2,y1,y2;
       void init(){scanf("%d%d%d%d",&x1,&x2,&y1,&y2);}
       bool covered(const Rect& r1)
       {
            return r1.x1<=x1 && x2<=r1.x2 && r1.y1<=y1 && y2<=r1.y2;
       }
}rect[5000];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
          for(int i=0;i<n;i++) rect[i].init();
          int ans=0;
          for(int i=0;i<n;i++)
              for(int j=0;j<n;j++) if(i!=j)
              {
                    if(rect[i].covered(rect[j])) {ans++;break;}
              }
          printf("%d\n",ans);
                  
    }
}
