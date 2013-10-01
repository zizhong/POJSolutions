#include<stdio.h>
int main()
{
    int sx,sy,ex,ey;
    while(scanf("%d%d",&sy,&sx),sx||sy)
    {
         scanf("%d%d",&ey,&ex);
         int map[13][13]={0},vst[13][13]={0};
         struct St
         {
                int x,y;
                int per;
                char way;
         }q[37];
         int head=0,tail=0;
         //draw the map
         sx<<=1,sy<<=1,ex<<=1,ey<<=1;
         sx--,sy--,ex--,ey--;
         int x1,y1,x2,y2;
         for(int i=0;i<3;i++)
         {
                 scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
                 x1<<=1,x2<<=1,y1<<=1,y2<<=1;
                 if(x1==x2)
                 {
                       if(y1>y2) for(int j=y2;j<=y1;j++) map[x1][j]=1;
                       else for(int j=y1;j<=y2;j++) map[x1][j]=1;
                 }
                 else if(x1>x2) for(int j=x2;j<=x1;j++) map[j][y1]=1;
                 else for(int j=x1;j<=x2;j++) map[j][y1]=1;
         }
         for(int i=0;i<12;i++) map[i][0]=map[0][i]=map[12][i]=map[i][12]=1;
         //breadth first search
         St st;
         st.x=sx,st.y=sy,st.way='\0';
         q[tail++]=st;
         vst[st.x][st.y]=1;
         while(tail!=head)
         {
              St cur=q[head++];
              if(cur.x==ex&&cur.y==ey) break;
              int x=cur.x,y=cur.y;
              if(map[x-1][y]==0&&vst[x-2][y]==0)
              {
                   St next;
                   vst[x-2][y]=1;
                   next.x=x-2,next.y=y,next.per=head-1,next.way='N';
                   q[tail++]=next;
              }
              if(map[x][y-1]==0&&vst[x][y-2]==0)
              {
                   St next;
                   vst[x][y-2]=1;
                   next.x=x,next.y=y-2,next.per=head-1,next.way='W';
                   q[tail++]=next;
              }
              if(map[x][y+1]==0&&vst[x][y+2]==0)
              {
                   St next;
                   vst[x][y+2]=1;
                   next.x=x,next.y=y+2,next.per=head-1,next.way='E';
                   q[tail++]=next;
              }
              if(map[x+1][y]==0&&vst[x+2][y]==0)
              {
                   St next;
                   vst[x+2][y]=1;
                   next.x=x+2,next.y=y,next.per=head-1,next.way='S';
                   q[tail++]=next;
              }
         }
         //draw the path
         int key=head-1,step=0;
         char path[37];
         while(q[key].way) path[step++]=q[key].way,key=q[key].per;
         for(int i=step-1;i>=0;i--) putchar(path[i]);
         puts("");
    }
}
