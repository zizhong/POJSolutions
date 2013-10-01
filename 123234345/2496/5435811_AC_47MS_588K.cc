#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
const int NIL=999999999;
int main()
{   //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int ncase;
    scanf("%d",&ncase);
    int t=ncase;
    while(t--)
    {
        printf("Scenario #%d:\n",ncase-t);
        
        int p,n,i,j,k;
        scanf("%d%d",&p,&n);
        
        int a[101][101]={0};
        int q[10000]={0};
        for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
           {
           scanf("%d",&a[i][j]);
           if(a[i][j]<0) a[i][j]=NIL;
           }
        
        for(k=1;k<=n;k++)
          for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(a[i][j]>a[i][k]+a[k][j])
                   a[i][j]=a[i][k]+a[k][j];
            }
         k=0;   
        for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
           if(i!=j) q[k++]=a[i][j];
        
        qsort(q,k,sizeof(q[0]),cmp);
        /*for(i=0;i<k;i++)
            printf("%d ",q[i]);*/
       // printf("\n");
        int r=k*p/100;
        if(k*p%100==0) r--;
        
        printf("%d\n\n",q[r]);
    }
}
