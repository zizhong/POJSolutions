#include<stdio.h>
const int N=255;
int d[N][N],n,B,min[N][N],max[N][N],q[N],mmin[N][N],mmax[N][N],head,tail;
void display(int f[N][N])
{
     for(int i=0;i<n;i++,puts(""))
        for(int j=0;j<n;j++)
           printf("%d ",f[i][j]);
     int x=20;
     while(x--) putchar('-');
     puts("");
}
void init()
{
     for(int i=0;i<n;i++)
     {
          head=tail=0;
          for(int j=0;j<n;j++)
          {
               while(head<tail&&d[i][j]>=d[i][q[tail-1]]) tail--;
               q[tail++]=j;
               if(j-q[head]>=B) head++;
               max[i][j]=d[i][q[head]];
          }
     }
     for(int i=0;i<n;i++)
     {
          head=tail=0;
          for(int j=0;j<n;j++)
          {
               while(head<tail&&d[i][j]<=d[i][q[tail-1]]) tail--;
               q[tail++]=j;
               if(j-q[head]>=B) head++;
               min[i][j]=d[i][q[head]];
          }
     }
     
     for(int i=0;i<n;i++)
     {
          head=tail=0;
          for(int j=0;j<n;j++)
          {
               while(head<tail&&max[j][i]>=max[q[tail-1]][i]) tail--;
               q[tail++]=j;
               if(j-q[head]>=B) head++;
               mmax[j][i]=max[q[head]][i];
          }
     }
     for(int i=0;i<n;i++)
     {
          head=tail=0;
          for(int j=0;j<n;j++)
          {
               while(head<tail&&min[j][i]<=min[q[tail-1]][i]) tail--;
               q[tail++]=j;
               if(j-q[head]>=B) head++;
               mmin[j][i]=min[q[head]][i];
          }
     }
     
     //display(min);
     //display(max);
     //display(mmin);
     //display(mmax);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int m;
    scanf("%d%d%d",&n,&B,&m);
    for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
           scanf("%d",&d[i][j]),min[i][j]=max[i][j]=d[i][j];
    init();
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x+=B-2,y+=B-2;
        printf("%d\n",mmax[x][y]-mmin[x][y]);
    }
}
