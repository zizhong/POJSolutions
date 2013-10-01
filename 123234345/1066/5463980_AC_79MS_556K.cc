#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct {double x,y;} Point;
Point line[31][2];
int n;
Point end;
int cmp(const void *a,const void *b)
{
    return *(double *)a>*(double *)b?1:-1;
}
int dblcmp(double d)
{
    if(fabs(d)<1e-10) return 0;
    return d>0?1:-1;
}
double det(double x1,double y1,double x2,double y2)
{
       return x1*y2-x2*y1;
}
double cross(Point a,Point b,Point c)
{
       return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
int segcross(Point a,Point b,Point c,Point d)
{
    return (dblcmp(cross(a,c,d))^dblcmp(cross(b,c,d)))==-2&&
           (dblcmp(cross(c,a,b))^dblcmp(cross(d,a,b)))==-2;
}
int counti(Point st)
{
    int i,j,cnt=0;
    for(i=0;i<n;i++)
    {
       cnt+=segcross(st,end,line[i][0],line[i][1]);
    }
    return cnt+1;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
       scanf("%lf%lf%lf%lf",&line[i][0].x,&line[i][0].y,&line[i][1].x,&line[i][1].y);
    scanf("%lf%lf",&end.x,&end.y);
    double x0[30],y0[30],x100[30],y100[30];
    int nx0=0,ny0=0,nx100=0,ny100=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
        {
            if(fabs(line[i][j].x-0)<1e-8) x0[nx0++]=line[i][j].y;
            if(fabs(line[i][j].x-100)<1e-8) x100[nx100++]=line[i][j].y;
            if(fabs(line[i][j].y-0)<1e-8) y0[ny0++]=line[i][j].x;
            if(fabs(line[i][j].y-0)<1e-8) y100[ny100++]=line[i][j].x;
        }
    }
    qsort(x0,nx0,sizeof(double),cmp);
    qsort(x100,nx100,sizeof(double),cmp);
    qsort(y0,ny0,sizeof(double),cmp);
    qsort(y100,ny100,sizeof(double),cmp);
    //x0
     int N=100,cnt=0;
    Point st;
    st.x=0,st.y=(0+x0[0])*0.5;
    cnt=counti(st);
    //printf("%d\n",cnt);
    if(N>cnt) N=cnt;
    for(i=1;i<nx0;i++)
    {
        st.x=0,st.y=(x0[i-1]+x0[i])*0.5;
        cnt=counti(st);
        if(N>cnt) N=cnt;
    }
    st.x=0,st.y=(100+x0[nx0-1])*0.5;
    cnt=counti(st);
    if(N>cnt) N=cnt;
   //x100
    st.x=100,st.y=(0+x100[0])*0.5;
    cnt=counti(st);
    if(N>cnt) N=cnt;
    for(i=1;i<nx100;i++)
    {
        st.x=100,st.y=(x100[i-1]+x100[i])*0.5;
        cnt=counti(st);
        if(N>cnt) N=cnt;
    }
    st.x=100,st.y=(100+x100[nx100-1])*0.5;
    cnt=counti(st);
    if(N>cnt) N=cnt;
    //y0
    st.y=0,st.x=(0+y0[0])*0.5;
    cnt=counti(st);
    if(N>cnt) N=cnt;
    for(i=1;i<ny0;i++)
    {
        st.y=0,st.x=(y0[i-1]+y0[i])*0.5;
        cnt=counti(st);
        if(N>cnt) N=cnt;
    }
    st.y=0,st.x=(100+y0[ny0-1])*0.5;
    cnt=counti(st);
    if(N>cnt) N=cnt;
   //y100
    st.y=100,st.x=(0+y100[0])*0.5;
    cnt=counti(st);
    if(N>cnt) N=cnt;
    for(i=1;i<ny100;i++)
    {
        st.y=100,st.x=(y100[i-1]+y100[i])*0.5;
        cnt=counti(st);
        if(N>cnt) N=cnt;
    }
    st.y=100,st.x=(100+y100[ny100-1])*0.5;
    cnt=counti(st);
    if(N>cnt) N=cnt;
   
    printf("Number of doors = %d\n",N);    
    
}









