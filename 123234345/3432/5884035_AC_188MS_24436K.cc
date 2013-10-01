#include<stdio.h>
#define SIZE 6144777
#define hash(x, y) (((x+20000)*40001+(y+20000))%SIZE)
int x[2000],y[2000];
int h[SIZE],hk;
int main()
{
    int n;
    scanf("%d",&n);
    {
        hk++;
        int ans=0;
        for(int i=0;i<n;i++)
        {
           scanf("%d%d",&x[i],&y[i]);
           h[hash(x[i],y[i])]=hk;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                 int vx0=x[j]-x[i],vy0=y[j]-y[i],
                     vx1=-vy0,vy1=vx0,
                     vx2=vy0,vy2=-vx0,
                     x3=x[j]+vx1,y3=y[j]+vy1,
                     x4=x3-vx0,y4=y3-vy0;
                 if(h[hash(x3,y3)]==hk&&h[hash(x4,y4)]==hk) ans++;
                 x3=x[j]+vx2,y3=y[j]+vy2;
                 x4=x3-vx0,y4=y3-vy0;
                 if(h[hash(x3,y3)]==hk&&h[hash(x4,y4)]==hk) ans++;
            }
        }
        printf("%d\n",ans/4);
    }
}
