#include<stdio.h>
#include<math.h>
#define max 0xfffffff
int mins[25],minv[25],n,m,ms;
void dfs(int cur_f,int last_r,int last_h,int leave_v,int sum_s)
{
     int i,j,max_h;
     if(sum_s+mins[cur_f]>=ms||leave_v<minv[cur_f]) return ;
     if(cur_f==0)
     {
          if(leave_v==0&&ms>sum_s) ms=sum_s;
          return ;
     }
     for(i=last_r-1;i>=cur_f;--i)
     {
         int kk=(int)((leave_v-minv[cur_f-1])/((double)(i*i)));
         max_h=kk<(last_h-1)?kk:(last_h-1);
         for(j=max_h;j>=cur_f;--j)
         {
             if(2*(leave_v-i*i*j)/i+sum_s+2*i*j>=ms) continue;
             int v=i*i*j,s=2*i*j;
             if(cur_f==m) s+=i*i;
             dfs(cur_f-1,i,j,leave_v-v,sum_s+s);
         }
     }
}
int main()
{
    int i;
    mins[0]=0,minv[0]=0;
    for(i=1;i<=20;i++)
        mins[i]=mins[i-1]+2*i*i,minv[i]=minv[i-1]+i*i*i;
    scanf("%d%d",&n,&m);
    {
         ms=max;
         int beg=(int)sqrt((double)n)+1;
         dfs(m,beg,beg,n,0);
         if(ms!=max) printf("%d\n",ms);
         else printf("0\n");
    }
}
