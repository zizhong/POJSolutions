#include<stdio.h>
#include<string.h>
const int N = 33;
char dun[N][N][N];
int vst[N][N][N];
struct Node
{
       int l,r,c;
       int step;
}q[N*N*N];
int head,tail;
int d[6][3]={{0,-1,0},{0,1,0},{0,0,-1},{0,0,1},{1,0,0},{-1,0,0}};
int main()
{
    int L,R,C;
    while(scanf("%d%d%d",&L,&R,&C),L+R+C)
    {
          memset(dun,'#',sizeof(dun));
          memset(vst,0,sizeof(vst));
          head=tail=0;
          int flag=0;
          for(int i=1;i<=L;i++)
          {
                  for(int j=1;j<=R;j++)
                  {
                          scanf("%s",dun[i][j]+1);
                          dun[i][j][C+1]='#';
                  }
          }
          Node st,ed;
          for(int i=0;i<L;i++)
          {
                  for(int j=1;j<=R;j++)
                          for(int k=1;k<=C;k++)
                                  if(dun[i][j][k]=='S') st.l=i,st.r=j,st.c=k,st.step=0;
                                  else if(dun[i][j][k]=='E') ed.l=i,ed.r=j,ed.c=k;
          }
          q[tail++]=st;
          vst[st.l][st.r][st.c]=1;
          while(head-tail)
          {
               Node cur=q[head++];
               Node next;
               next.step=cur.step+1;
               if(dun[cur.l][cur.r][cur.c]=='E')
               {
                     flag=1;
                     printf("Escaped in %d minute(s).\n",cur.step);
                     break;
               }
               for(int h=0;h<6;h++)
               {
                     next.l=cur.l+d[h][0],next.r=cur.r+d[h][1],next.c=cur.c+d[h][2];
                     if(dun[next.l][next.r][next.c]!='#'&&vst[next.l][next.r][next.c]==0)
                     {
                           q[tail++]=next;
                           vst[next.l][next.r][next.c]=1;
                     }
               }
          }
          if(flag==0) puts("Trapped!");
    }
}
