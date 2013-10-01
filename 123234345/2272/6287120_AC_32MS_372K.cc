#include<stdio.h>
#include<math.h>
int d[6]={3*3,6*6,9*9,12*12,15*15,21*21};
int s[6]={100,80,60,40,20,0};
int main()
{
        double x[7],y[7];
    while(scanf("%lf%lf",&x[1],&y[1]),fabs(x[1]+100)>1e-8)
    {
          for(int i=2;i<=6;i++)
             scanf("%lf%lf",&x[i],&y[i]);
          int G[2]={0};
          for(int i=1;i<=6;i++)
          {
                  for(int j=0;j<6;j++)
                     if((x[i]*x[i]+y[i]*y[i])<d[j]||fabs(x[i]*x[i]+y[i]*y[i]-d[j])<1e-8)
                     {
                          G[(i-1)/3]+=s[j];
                          break;
                     }
          }
          int win=0;
          if(G[0]>G[1]) win=1;
          else if(G[0]<G[1]) win=2;
          if(win==0) printf("SCORE: %d to %d, TIE.\n",G[0],G[1]);
          else printf("SCORE: %d to %d, PLAYER %d WINS.\n",G[0],G[1],win);
    }
}
