#include<stdio.h>
#include<math.h>
const int KMAX=999999999;
int main()
{
    int t;
    scanf("%d",&t);
    printf("INTERSECTING LINES OUTPUT\n");
    while(t--)
    {
        int x1,y1,x2,y2,x3,y3,x4,y4;
        scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        double k1,k2;
        if(x2==x1) k1=KMAX;
        else k1=(y2-y1)*1.0/(x2-x1);
        if(x3==x4) k2=KMAX;
        else k2=(y4-y3)*1.0/(x4-x3);
        if(fabs(k2-k1)<1e-8)
        {
            if(fabs((y2-y1)*(x3-x1)-(y3-y1)*(x2-x1))<1e-8)
                   printf("LINE\n");
            else printf("NONE\n");
        }
        else
        {
            printf("POINT");
            if(fabs(k1-KMAX)<1e-8)
                printf(" %.2f %.2f\n",double(x1),k2*(x1-x3)+y3);
            else if(fabs(k2-KMAX)<1e-8)
                printf(" %.2f %.2f\n",double(x3),k1*(x3-x1)+y1);
            else
            {
                double x0=(y3-y1+k1*x1-k2*x3)/(k1-k2),
                       y0=k1*(x0-x1)+y1;
                printf(" %.2f %.2f\n",x0,y0);
            }
        }
    }
    printf("END OF OUTPUT\n");
}
