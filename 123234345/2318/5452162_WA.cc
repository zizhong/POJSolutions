#include<stdio.h>
#include<stdlib.h>
int board[1001][2];
int toy[1001][2];
int m,x1,y1,x2,y2,n;
int cmp(const void *a,const void *b)
{
     return ((int *)a)[0]-((int *)b)[0];
}
int cmp1(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
void calx(double &xl,double& xr,int j,int i)
{
     
     if(j==0) xl=0;
     else xl=(board[j-1][0]==board[j-1][1])?
              board[j-1][0]:((toy[i][1]-y1)*(board[j-1][1]-board[j-1][0])*1.0/(y2-y1)+board[j-1][0]);
     if(j==n) xr=x2;
     else xr=(board[j][0]==board[j][1])?
              board[j][0]:((toy[i][1]-y1)*(board[j][1]-board[j][0])*1.0/(y2-y1)+board[j][0]);
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int first=1;
    while(scanf("%d",&n)&&n)
    {
        int num[1002]={0},i,j;
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        for(i=0;i<n;i++)
           scanf("%d%d",&board[i][0],&board[i][1]);
        for(i=0;i<m;i++)
        {
           scanf("%d%d",&toy[i][0],&toy[i][1]);
        }
        qsort(toy,m,sizeof(int)*2,cmp);
        qsort(board,n,sizeof(int)*2,cmp);
        /*for(i=0;i<m;i++)
        {
           printf("(%d,%d)",toy[i][0],toy[i][1]);
        }
        printf("\n");*/
        j=1;
        for(i=0;i<m;i++)
        {
            double xl,xr;
            calx(xl,xr,j,i);
            while(toy[i][0]<xl&&toy[i][0]<xr)
            {
                 j--;
                 calx(xl,xr,j,i);
            }
            while(toy[i][0]>xl&&toy[i][0]>xr)
            {
                 j++;
                 calx(xl,xr,j,i); 
            }
            num[j]++;
        }
        qsort(num,n+1,sizeof(num[0]),cmp1);
        printf("Box\n");
        int k=0;
        while(num[k]==0) k++;
        int nm=num[k],cnt=1;
        for(i=k+1;i<=n;i++)
        {
            if(nm==num[i])
            {
                cnt++;
            }
            else
            {
                printf("%d: %d\n",nm,cnt);
                nm=num[i],cnt=1;
            }
        }
        printf("%d: %d\n",nm,cnt);
    }
}
