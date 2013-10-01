#include<stdio.h>
int main()
{
    int s,t,m,T=0;
    while(scanf("%d%d%d",&s,&t,&m),s)
    {
         int sch[101][3]={0},st[101]={0};
         for(int i=0;i<s;i++)
         {
              int x;
              scanf("%d",&x);
              scanf("%d%d",&sch[x][1],&sch[x][2]);
         }
         for(int i=0;i<t;i++)
         {
             int id,tn;
             scanf("%d%d",&id,&tn);
             if(tn>=m)sch[id][0]=1;
         }
         int num=0;
         for(int i=1;i<=s;i++)
            num+=sch[i][0]+sch[i][1]+sch[i][2];
         printf("Case %d: %d\n",++T,num);
    }
}
