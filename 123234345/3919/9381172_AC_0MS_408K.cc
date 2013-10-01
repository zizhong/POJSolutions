#include<stdio.h>
#include<math.h>
int mark[1000000];
double cc[1000000][2];
double rr[1000000];
int cnt;
int tower[11][3],road[11][2];
double dd(int ti,int mi)
{
       return sqrt((tower[ti][0]-cc[mi][0])*(tower[ti][0]-cc[mi][0])+(tower[ti][1]-cc[mi][1])*(tower[ti][1]-cc[mi][1]));
}
int main()
{
    int t,r;
    while(scanf("%d",&t)!=EOF&&t)
    {
          scanf("%d",&r);
          for(int i=0;i<t;i++)
             scanf("%d%d%d",&tower[i][0],&tower[i][1],&tower[i][2]);
          for(int i=0;i<=r;i++)
             scanf("%d%d",&road[i][0],&road[i][1]);
          cnt=0;
          cc[cnt][0]=road[0][0],cc[cnt][1]=road[0][1];
          cnt++;
          double pre=0;
          for(int i=0;i<r;i++)
          {
                 rr[i]=sqrt((road[i][0]-road[i+1][0])*(road[i][0]-road[i+1][0])+(road[i][1]-road[i+1][1])*(road[i][1]-road[i+1][1]));
                 int nm=(int)(rr[i]+pre);                 
                 for(int j=0;j<nm;j++)
                 {
                      double del=j+1-pre;
                      cc[cnt][0]=(road[i+1][0]-road[i][0])*del/rr[i]+road[i][0];
                      cc[cnt][1]=(road[i+1][1]-road[i][1])*del/rr[i]+road[i][1];
                      cnt++;
                 }
                 pre=pre+rr[i]-nm;
          }
          if(!(pre<0.5)) cc[cnt][0]=road[r][0],cc[cnt][1]=road[r][1],cnt++;
          int ans=0;
          double min=0;
          for(int i=0;i<t;i++)
              if((min*dd(i,0)*dd(i,0))+1e-9<tower[i][2])
                  min=tower[i][2]/dd(i,0)/dd(i,0),ans=i;
          printf("(0,%c)",ans+'A');
          for(int i=1;i<cnt;i++)
          {
                int ans2;
                double min=0;
                for(int j=0;j<t;j++)
                   if((min*dd(j,i)*dd(j,i))+1e-9<tower[j][2])
                        min=tower[j][2]/dd(j,i)/dd(j,i),ans2=j;
                if(ans2!=ans)
                {
                      printf(" (%d,%c)",i,ans2+'A');
                      ans=ans2;
                }
          }
          puts("");
    }
}