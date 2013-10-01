#include<stdio.h>
int p[101][2];
int main()
{
    int n,k;
    while(scanf("%d",&n)!=EOF&&n)
    {
        scanf("%d",&k);
        for(int i=1;i<=n;i++) p[i][0]=p[i][1]=0;
        while(k--)
        {
            int n1,n2;
            char s1[16],s2[16];
            scanf("%d%s%d%s",&n1,s1,&n2,s2);
            if(s1[0]==s2[0]) continue;
            p[n1][1]++,p[n2][1]++;
            if(s1[0]=='r'&&s2[0]=='p') p[n2][0]++;
            if(s1[0]=='p'&&s2[0]=='r') p[n1][0]++;
            if(s1[0]=='r'&&s2[0]=='s') p[n1][0]++;
            if(s1[0]=='s'&&s2[0]=='r') p[n2][0]++;
            if(s1[0]=='s'&&s2[0]=='p') p[n1][0]++;
            if(s1[0]=='p'&&s2[0]=='s') p[n2][0]++;
        }
        for(int i=1;i<=n;i++)
           if(p[i][1]==0) printf("-\n");
           else printf("%.3f\n",p[i][0]*1.0/p[i][1]);
        printf("\n");
    }
}
