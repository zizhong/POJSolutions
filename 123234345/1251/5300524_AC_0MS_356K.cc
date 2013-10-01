#include<stdio.h>
#define NIL 9999
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int v[27][27]={0};
        int a[3][27]={0};
        int i,j,k,tail,min;
        for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
            if(i!=j) v[i][j]=NIL;
        for(i=1;i<n;i++)
        {
            char start='#';
            while(start<'A'||start>'Z')
            scanf("%c",&start);
            int m;
            scanf("%d",&m);
            while(m--)
            {
               char end='#';
               while(end<'A'||end>'Z')
                  scanf("%c",&end);
               scanf("%d",&v[start-'A'+1][end-'A'+1]);
               v[end-'A'+1][start-'A'+1]=v[start-'A'+1][end-'A'+1];
            }
        }
        a[0][1]=0;
        a[2][1]=1;
        for(i=1;i<=n;i++)
        {
           a[0][i]=v[1][i];
           a[1][i]=1;
        }
        while(1)
        {
             min=NIL;
             for(i=1;i<=n;i++)
                if(a[2][i]==0&&a[0][i]<min)
                {
                    min=a[0][i];
                    tail=i;
                }
             if(min==NIL) break;
             a[2][tail]=1;
             for(i=1;i<=n;i++)
                if(a[2][i]==0&&a[0][i]>v[tail][i])
                {
                   a[0][i]=v[tail][i];
                   a[1][i]=tail;
                }
        }
        int sum=0;
        for(i=1;i<=n;i++) sum+=a[0][i];
        printf("%d\n",sum);
    }
}
