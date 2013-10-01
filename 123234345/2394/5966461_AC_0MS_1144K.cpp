#include<stdio.h>
const int N = 501,MAX=999999999;
int F,P,C,M;
int g[N][N],cpos[101],a[N][3];
int main()
{
    scanf("%d%d%d%d",&F,&P,&C,&M);
    for(int i=1;i<=F;i++)
        for(int j=1;j<=F;j++)
           if(i!=j) g[i][j]=MAX;
    for(int i=0;i<P;i++)
    {
        int f1,f2,d;
        scanf("%d%d%d",&f1,&f2,&d);
        if((g[f1][f2]>d||!g[f1][f2])&&f1!=f2) g[f1][f2]=g[f2][f1]=d;
    }
    for(int i=1;i<=C;i++)
        scanf("%d",&cpos[i]);
    for(int i=1;i<=F;i++)
    {
         a[i][0]=g[i][1];
         a[i][1]=1;
         a[i][2]=0;
    }
    a[1][2]=1;
    while(1)
    {
            int min=MAX,tail=-1;
            for(int i=1;i<=F;i++)
               if(!a[i][2]&&a[i][0]<min)
                   min=a[i][0],tail=i;
            if(min==MAX) break;
            a[tail][2]=1;
            for(int i=1;i<=F;i++)
            {
                   if(!a[i][2]&&(a[i][0]>g[i][tail]+a[tail][0]))
                   {
                         a[i][0]=g[i][tail]+a[tail][0];
                         a[i][1]=tail;
                   }
            }
    }
    int flag[102]={0};
    for(int i=1;i<=C;i++)
    {
          if(a[cpos[i]][0]<=M) flag[0]++,flag[i]=1;
    }
    printf("%d\n",flag[0]);
    for(int i=1;i<=C;i++)
       if(flag[i]) printf("%d\n",i);
    //scanf("%d",&C);
}
