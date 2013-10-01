#include<stdio.h>
int main()
{
    int n;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n)&&n!=-1)
    {
        int clay[10]={0};
        char sdt[10][10];
        int i,ave,sum=0,b,s;
        for(i=0;i<n;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            clay[i]=a*b*c;
            sum+=clay[i];
            scanf("%s",sdt[i]);
        }
        ave=sum/n;
        for(i=0;i<n;i++)
        {
           if(clay[i]<ave) s=i;
           if(clay[i]>ave) b=i;
        }
        printf("%s took clay from %s.\n",sdt[b],sdt[s]);
    }
}
