#include<stdio.h>
#include<stdlib.h>
int board[5001][2];
int toy[5001][2];
int m,x1,y1,x2,y2,n;
int cmp(const void *a,const void *b)
{
     return ((int *)a)[0]-((int *)b)[0];
}
void calx(double &xl,double& xr,int j,int i)
{
     
     if(j==0) xl=0;
     else xl=(board[j][0]==board[j][1])?
              board[j][0]:((toy[i][1]-y1)*(board[j][1]-board[j][0])*1.0/(y2-y1)+board[j][0]);
     if(j==n) xr=x2;
     else xr=(board[j+1][0]==board[j+1][1])?
              board[j+1][0]:((toy[i][1]-y1)*(board[j+1][1]-board[j+1][0])*1.0/(y2-y1)+board[j+1][0]);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int first=1;
    while(scanf("%d",&n)&&n)
    {
        int num[5000]={0},i,j;
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        for(i=1;i<=n;i++)
           scanf("%d%d",&board[i][0],&board[i][1]);
        for(i=1;i<=m;i++)
        {
           scanf("%d%d",&toy[i][0],&toy[i][1]);
        }
        qsort(toy,m,sizeof(toy[0]),cmp);
        j=1;
        for(i=1;i<=m;i++)
        {
            double xl,xr;
            calx(xl,xr,j,i);
            while(toy[i][0]<xl&&toy[i][0]<xr)
            {
                 j--;
                 calx(xl,xr,j,i);
            }
            //printf("( %d,",j);
            while(toy[i][0]>xl&&toy[i][0]>xr)
            {
                 j++;
                 calx(xl,xr,j,i); 
            }
            //printf("%d) ",j);
            num[j]++;
        }
        if(!first) printf("\n");
        for(i=0;i<=n;i++)
                printf("%d: %d\n",i,num[i]);
        first=0;
    }
}
