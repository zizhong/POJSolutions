#include<stdio.h>
int main()
{
    int N,R,Q;
    int nt=0;
    while(scanf("%d",&N)&&N)
    {
        int r[1000][2]={0};
        scanf("%d",&R);
        for(int i=0;i<R;i++)
           scanf("%d%d",&r[i][0],&r[i][1]);
        printf("Genome %d\n",++nt);
        scanf("%d",&Q);
        while(Q--)
        {
            int k;
            scanf("%d",&k);
            for(int i=0;i<R;i++)
            {
                 if(r[i][0]<=k&&r[i][1]>=k)
                     k=r[i][0]+r[i][1]-k;
            }
            printf("%d\n",k);
        }
    }
}
