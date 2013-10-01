#include<stdio.h>
#include<math.h>
int kind[4][2]={{0,0},{0,2},{2,0},{2,2}};
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j,k,h;
        double  s[128][4]={0};
        scanf("%d",&n);
        for(i=0;i<n;i++)
           scanf("%lf%lf%lf%lf",&s[i][0],&s[i][1],&s[i][2],&s[i][3]);
        bool flag=false;
        if(n==1||n==2) flag=true;
        for(i=0;i<n;i++)
          for(j=i+1;j<n;j++)
          {
              for(k=0;k<4;k++)
              {
                  double x1=s[i][kind[k][0]],y1=s[i][kind[k][0]+1],
                         x2=s[j][kind[k][1]],y2=s[j][kind[k][1]+1];
                  if(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<1e-6) continue;
                  for(h=0;h<n;h++)
                  {
                      if(h==i||h==j) continue;
                      double f1=(y2-y1)*(s[h][0]-x1)+(y1-s[h][1])*(x2-x1),
                             f2=(y2-y1)*(s[h][2]-x1)+(y1-s[h][3])*(x2-x1);
                      if(!(f1*f2<=0||fabs(f1)<1e-6||fabs(f2)<1e-6))
                              break;
                  }
                  if(h==n)
                  {
                       flag=true;
                       goto END;
                  }
              }
          }
        END:;
        if(flag) printf("Yes!\n");
        else printf("No!\n");
    }
}
