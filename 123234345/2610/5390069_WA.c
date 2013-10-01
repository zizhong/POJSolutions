#include<stdio.h>
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    double x1,y1,x2,y2,hx,hy;
    int esc=0;
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    while(scanf("%lf%lf",&hx,&hy)!=EOF)
    {
        double d1=sqrt((hx-x1)*(hx-x1)+(hy-y1)*(hy-y1));
        double d2=sqrt((hx-x2)*(hx-x2)+(hy-y2)*(hy-y2));
        if((d1*2<d2))
        {
            esc=1;
        }
    }
    if(esc) printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",hx,hy);
    else printf("The gopher cannot escape.\n");
    getchar();getchar();
}
