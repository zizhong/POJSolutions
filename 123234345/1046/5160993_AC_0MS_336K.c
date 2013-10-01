#include<stdio.h>
int main()
{
    int a[16][3]={0},x,y,z,i;
    for(i=0;i<16;i++)
       scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    while(scanf("%d%d%d",&x,&y,&z))
    {
        int d[16],min=9999999;
        if(x==-1&&y==-1&&z==-1) break;
        for(i=0;i<16;i++)
            d[i]=sqrt((x-a[i][0])*(x-a[i][0])+(y-a[i][1])*(y-a[i][1])+(z-a[i][2])*(z-a[i][2]));       
        for(i=0;i<16;i++)
           if(min>d[i]) min=d[i];
        for(i=0;i<16;i++)
           if(abs(d[i]-min)<1e-20) break;
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",x,y,z,a[i][0],a[i][1],a[i][2]);
    }
}
