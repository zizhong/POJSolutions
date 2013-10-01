#include<stdio.h>
int cro[1200][1200],N;
int lowbit(int n){return n&(-n);}
void update(int i,int j,int t)
{
     int temp=j;
     while(i<=N)
     {
          temp=j;
          while(temp<=N)
          {
               cro[i][temp]+=t;
               temp+=lowbit(temp);
          }
          i+=lowbit(i);
     }
}
int sum(int i,int j)
{
    int res=0,temp;
    while(i>0)
    {
         temp=j;
         while(temp>0) 
         {
            res+=cro[i][temp];
            temp-=lowbit(temp);
         }
         i-=lowbit(i);
    }
    return res;
}
int main()
{
    int k;
    while(scanf("%d",&k)==1&&k!=3)
    {
        if(k==0) scanf("%d",&N);
        else if(k==1)
        {
             int x,y,a;
             scanf("%d%d%d",&x,&y,&a);
             update(x+1,y+1,a);
        }
        else if(k==2)
        {
            int res=0;
            int l,b,r,t;
            scanf("%d%d%d%d",&l,&b,&r,&t);
            res=sum(r+1,t+1)-sum(l,t+1)-sum(r+1,b)+sum(l,b);
            printf("%d\n",res);
        }
    }    
}
