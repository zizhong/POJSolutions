#include<stdio.h>
#include<cmath>
#include<string.h>
const int MAX=1000000;
bool flag[MAX+1];
void prime()
{
     int max=int(sqrt(MAX)),i,j;
     memset(flag,true,sizeof(flag));
     flag[0]=flag[1]=false;
     for(i=2;i<=max;i++)
         if(flag[i])
         {
            for(j=i*i;j<=MAX;j+=i)
                flag[j]=false;
         }
} 
int main()
{
    prime();
    int l,u;
    while(scanf("%d%d",&l,&u)+1)
    {
        if(l+u==-2) break;
        int x=0,y=0;
        int i;
        for(i=l;i<=u;i++)
           if(flag[i])
           {
               x++;
               if((i-1)%4==0) y++;
           }
        printf("%d %d %d %d\n",l,u,x,y);
    }
}
