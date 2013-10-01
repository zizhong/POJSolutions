#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
    return a>b?b:a;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int tree[100][2]={0};
int n;
int num(int x1,int y1,int x2,int y2)
{
    int sum=0;
    for(int i=0;i<n;i++)
        if(x1<=tree[i][0]&&tree[i][0]<=x2&&y1<=tree[i][1]&&tree[i][1]<=y2) sum++;
    return sum;
}
int dis2(int x1,int y1,int x2,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int d;
        scanf("%d%d",&n,&d);
        for(int i=0;i<n;i++)
           scanf("%d%d",&tree[i][0],&tree[i][1]);
        int rest=d*d*2;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=max(num(tree[i][0]-d,tree[i][1],tree[i][0],tree[i][1]+d),sum);
            sum=max(num(tree[i][0],tree[i][1],tree[i][0]+d,tree[i][1]+d),sum);
            sum=max(num(tree[i][0]-d,tree[i][1]-d,tree[i][0],tree[i][1]),sum);
            sum=max(num(tree[i][0],tree[i][1]-d,tree[i][0]+d,tree[i][1]),sum);
        }
        for(int i=0;i<n;i++)
        {
             for(int j=i+1;j<n;j++)
             {
                 if(tree[i][0]==tree[j][0]||tree[i][1]==tree[j][1]) continue;
                 int x1=tree[i][0],y1=tree[i][1],x2=tree[j][0],y2=tree[j][1];
                 if(dis2(x1,y1,x2,y2)<rest)
                 {
                      if((x1-x2)*(y1-y2)>0)
                      {
                         sum=max(sum,num(min(x1,x2),max(y1,y2)-d,min(x1,x2)+d,max(y1,y2)));
                         sum=max(num(max(x1,x2)-d,min(y1,y2),max(x1,x2),min(y1,y2)+d),sum);
                      }
                      else
                      {
                          sum=max(num(min(x1,x2),min(y1,y2),min(x1,x2)+d,min(y1,y2)+d),sum);
                          sum=max(num(max(x1,x2),max(y1,y2),max(x1,x2)-d,max(y1,y2)-d),sum);
                      }
                 }
             }
        }
        printf("%d\n",sum);
    }
}
