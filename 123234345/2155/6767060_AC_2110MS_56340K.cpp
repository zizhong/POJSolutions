#include<stdio.h>
const int N=1001;
int n,m,ans;
struct Node
{
       int x,y,v;
};
struct Seg
{
       Node a[3*N];
       int x,y;
}seg[3*N];
void build(int x,int y,int num,Node *seg2)
{
     seg2[num].x=x;
     seg2[num].y=y;
     seg2[num].v=0;
     int mid=x+y>>1;
     if(x==y) return ;
     build(x,mid,2*num+1,seg2);
     build(mid+1,y,2*num+2,seg2);
}
void create(int x,int y,int num)
{
     seg[num].x=x;
     seg[num].y=y;
     build(1,n,0,seg[num].a);
     int mid=x+y>>1;
     if(x==y) return ;
     create(x,mid,2*num+1);
     create(mid+1,y,2*num+2);
}
void insert_y(int l,int r,Node *seg2,int num)
{
     if(l<=seg2[num].x&&r>=seg2[num].y) 
     {
             seg2[num].v^=1;
             return ;
     }
     if(seg2[num].x==seg2[num].y) return ;
     seg2[2*num+1].v^=seg2[num].v,seg2[2*num+2].v^=seg2[num].v;
     seg2[num].v=0;
     int mid=seg[num].x+seg[num].y>>1;
     if(l<=mid) insert_y(l,r,seg2,num*2+1);
     if(r>mid) insert_y(l,r,seg2,num*2+2); 
}
void insert_x(int x1,int y1,int x2,int y2,int num) 
{
     if(x1<=seg[num].x&&x2>=seg[num].y) 
     {
           insert_y(y1,y2,seg[num].a,0);
           return ;
     }
     if(seg[num].x==seg[num].y) return ;
     int mid=seg[num].x+seg[num].y>>1;
     if(x1<=mid) insert_x(x1,y1,x2,y2,num*2+1);
     if(x2>mid) insert_x(x1,y1,x2,y2,num*2+2); 
}
void find_y(int y,Node *seg2,int num)
{
    if(y==seg2[num].x&&y==seg2[num].y) ans+=seg2[num].v;
    if(seg2[num].x==seg2[num].y) return;
    seg2[2*num+1].v^=seg2[num].v,seg2[2*num+2].v^=seg2[num].v;
    seg2[num].v=0;
    int mid=seg2[num].x+seg2[num].y>>1;
    if(y<=mid) find_y(y,seg2,2*num+1);
    else find_y(y,seg2,2*num+2);
}
void find(int x,int y,int num)
{
     if(seg[num].x<=x&&seg[num].y>=x)
     {
           find_y(y,seg[num].a,0);
           //return ;
     }
     if(seg[num].x==seg[num].y) return;
     int mid=seg[num].x+seg[num].y>>1;
     if(x<=mid) find(x,y,2*num+1);
     else find(x,y,2*num+2);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
          scanf("%d%d",&n,&m);
          create(1,n,0);
          while(m--)
          {
                    char s[2];
                    scanf("%s",s);
                    if(s[0]=='C')
                    {
                           int x1,y1,x2,y2;
                           scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                           insert_x(x1,y1,x2,y2,0);
                    }
                    else
                    {
                        int x,y;
                        ans=0;
                        scanf("%d%d",&x,&y);
                        find(x,y,0);
                        printf("%d\n",ans%2);
                    }
          }
          if(T) puts("");
    }
}
