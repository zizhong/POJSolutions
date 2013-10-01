#include<stdio.h>
#include<string.h>
struct Node
{
       int x,y,k,m,f;
}q[6400*4];
int way[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int head,tail;
int main()
{
    int h,w,nBoard=0;
    while(scanf("%d%d",&w,&h),w||h)
    {
          printf("Board #%d:\n",++nBoard);
          char bd[100][100];
          memset(bd,0,sizeof(bd));
          for(int i=1;i<=h;i++)
          {
               getchar();
               for(int j=1;j<=w;j++)
                   bd[i][j]=getchar();
          }
          int sx,sy,ex,ey,nP=0;
          while(scanf("%d%d%d%d",&sx,&sy,&ex,&ey),sx||sy||ex||ey)
          {
               printf("Pair %d: ",++nP);
               int ans=9999999;
               head=0,tail=1;
               int flag=0;
               q[head].x=sx,q[head].y=sy,q[head].m=0,q[head].f=0,q[head].k=-1;
               int vst[4][100][100]={0};
               vst[0][sy][sx]=vst[1][sy][sx]=vst[2][sy][sx]=vst[3][sy][sx]=1;
               while(head!=tail)
               {                    
                    Node node=q[head++];                    
                    //printf("\nx=%4d y=%4d m=%d",node.x,node.y,node.m);
                    if(node.x==ex&&node.y==ey)
                    {
                           flag=1;
                           if(ans>node.m) ans=node.m;
                    }
                    if(node.f) continue;
                    for(int i=0;i<4;i++)
                    {
                          Node next;
                          next.x=node.x+way[i][0],next.y=node.y+way[i][1],next.m=node.m;
                          if(vst[i][next.y][next.x]==0&&(next.x>=0)&&(next.x<=w+1)&&(next.y>=0)&&(next.y<=h+1))
                          {
                                if(bd[next.y][next.x]=='X') next.f=1;
                                else next.f=0;
                                next.k=i;
                                if(node.k!=next.k) next.m++;
                                q[tail++]=next;
                                vst[i][next.y][next.x]=1;
                          }
                    }
               }
               if(flag==0) printf("impossible.\n");
               else printf("%d segments.\n",ans);
          }
          puts("");
    }
}
