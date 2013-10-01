#include<stdio.h>
#include<string.h>
const int N=1100,M=50000;
struct Node
{
    int from,to,next;
}road[M],edge[M];
int head1[N],head[N],now1,now,nn,Bcnt,index,top;
int DFN[N],low[N],stack[N],instack[N],Belong[N],topovst[N];
void add_edge(int f,int t)
{
     edge[now].from=f;
     edge[now].to=t;
     edge[now].next=head[f];
     head[f]=now++;
}
void tarjan(int i)
{
     int j;
     DFN[i]=low[i]=++index;
     instack[i]=1;
     stack[++top]=i;
     int h,t;
     for(h=head[i];h!=-1;h=edge[h].next)
     {
          t=edge[h].to;
          if(!DFN[t])
          {
               tarjan(t);
               if(low[t]<low[i]);
               low[i]=low[t];
          }
          else if(instack[t]&&DFN[t]<low[i])
                low[i]=DFN[t];
     }
     if(low[i]==DFN[i])
     {
          Bcnt++;
          do
          {
               j=stack[top--];
               instack[j]=0;
               Belong[j]=Bcnt;
          }while(j!=i);
     }
}
bool judge()
{
     int i;
     for(i=1;i<=nn;i++)
     {
         if(Belong[2*i-1]==Belong[2*i])
             return false;
     }
     return true;
}
void init()
{
     now1=top=Bcnt=index=now=0;
     memset(DFN,0,sizeof(DFN));
     memset(head,-1,sizeof(head));
     memset(head1,-1,sizeof(head1));
}
int line[600][2];
int id[600];
int main()
{
    int n,m,i,j,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
          for(i=1;i<=m;i++)
          {
               scanf("%d%d",&line[i][0],&line[i][1]);
               if(line[i][0]>line[i][1])
               {
                    int tmp=line[i][0];
                    line[i][0]=line[i][1];
                    line[i][1]=tmp;
               }
          }
          nn=0;
          memset(id,0,sizeof(id));
          init();
          int k1,k2;
          for(i=1;i<=m;i++)
             for(j=i+1;j<=m;j++)
                 if((line[i][0]<line[j][0]&&line[i][1]>line[j][0]&&line[i][1]<line[j][1])||
                    (line[i][0]>line[j][0]&&line[i][0]<line[j][1]&&line[i][1]>line[j][1]))
                    {
                        if(!id[i])
                            id[i]=++nn;
                        if(!id[j])
                            id[j]=++nn;
                        k1=id[i];
                        k2=id[j];
                        add_edge(2*k1-1,2*k2);
                        add_edge(2*k2,2*k1-1);
                        add_edge(2*k1,2*k2-1);
                        add_edge(2*k2-1,2*k1);
                    }
          for(i=1;i<=nn*2;i++)
             if(!DFN[i])
                   tarjan(i);
          puts(judge()?"panda is telling the truth...":"the evil panda is lying again");
    }
}
