#include<stdio.h>
#include<stdlib.h>
int max,dx,dy,len,cx,cy;
struct Point
{
       short x,y;
}p[5000];
bool table[5000][5000];
int cmp(const void *a,const void *b)
{
    Point *p1=(Point *)a;
    Point *p2=(Point *)b;
    return p1->x - p2->x?p1->x - p2->x:p1->y - p2->y;
}
int main()
{
    int r,c,n;
    scanf("%d%d%d",&r,&c,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].x--,p[i].y--;
        table[p[i].x][p[i].y]=true;
    }
    qsort(p,n,sizeof(p[0]),cmp);
    for(int i=0;i<n;i++)
       for(int j=i+1;j<n;j++)
       {
            int dx=p[j].x-p[i].x,
                dy=p[j].y-p[i].y,
                cx=p[i].x-dx,
                cy=p[i].y-dy;
            if(cx>=0&&cy>=0&&cy<c) continue;
            if(dx&&dx*max>r) continue;
            if(dy&&(dy*max>c||-dy*max>c)) continue;
            
            cx=p[j].x+dx,cy=p[j].y+dy;
            len=2;
            while(cy>=0&&cx<r&&cy<c)
            {
                 if(!table[cx][cy]) goto end;
                 len++;
                 cx+=dx,cy+=dy;
            }
            if(len>=3&&len>max) max=len;
            end:;
       }
       printf("%d\n",max);
       //scanf("%d%d%d",&r,&c,&n);
}
