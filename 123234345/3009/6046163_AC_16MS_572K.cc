#include<stdio.h>
#include<string.h>
bool G[21][21];
int w,h,_min;
struct Node
{
       int x,y,b;
}st,et;
void DFS(Node node)
{
     if(node.x==et.x&&node.y==et.y)
     {
           if(node.b<_min) _min=node.b;
           return ;
     }
     if(node.b+1>=_min) return ;
     Node mt=node;
     while(G[mt.x][mt.y])
     {
          mt.x++;
          if(mt.x==et.x&&mt.y==et.y)
          {
               if(node.b+1<_min) _min=node.b+1;
               return ;
          }
     }
     mt.x--;
     if(mt.x+1<=h&&mt.x!=node.x)
     {
          mt.b=node.b+1;
          G[mt.x+1][mt.y]=1;
          DFS(mt);
          G[mt.x+1][mt.y]=0;
     }
     mt=node;
     while(G[mt.x][mt.y]) 
     { 
        mt.y++;//y+方向 
        if(mt.x==et.x&&mt.y==et.y) 
        { 
            if(node.b+1<_min) 
                _min = node.b+1; 
            return ; 
        } 
     } 
    mt.y--; 
    if(( mt.y+1 <= w ) && ( mt.y != node.y ))
    { 
        mt.b=node.b+1; 
        G[mt.x][mt.y+1]=1; 
        DFS(mt); 
        G[mt.x][mt.y+1]=0; 
    } 
    mt = node; 
    while(G[mt.x][mt.y]) 
    { 
        mt.x--;//x-方向 
        if(mt.x==et.x&&mt.y==et.y) 
        { 
            if(node.b+1<_min) 
                _min = node.b+1; 
            return ; 
        } 
    } 
    mt.x++; 
    if(( mt.x-1 > 0) && ( mt.x != node.x )){ 
        mt.b=node.b+1; 
        G[mt.x-1][mt.y]=1; 
        DFS(mt); 
        G[mt.x-1][mt.y]=0; 
    } 

    mt = node; 
    while(G[mt.x][mt.y]) 
    { 
        mt.y--;//y-方向 
        if(mt.x==et.x&&mt.y==et.y) 
        { 
            if(node.b+1<_min) 
                _min = node.b+1; 
            return ; 
        } 
    } 
    mt.y++; 
    if(( mt.y-1 > 0) && ( mt.y != node.y)){ 
        mt.b=node.b+1; 
        G[mt.x][mt.y-1]=1; 
        DFS(mt); 
        G[mt.x][mt.y-1]=0; 
    } 
}
int main()
{
    int e;
    while(scanf("%d%d",&w,&h),w||h)
    {
          memset(G,0,sizeof(G));
          for(int i=1;i<=h;i++)
             for(int j=1;j<=w;j++)
             {
                 G[i][j]=1;
                 scanf("%d",&e);
                 if(e==1) G[i][j]=0;
                 else if(e==2)
                      st.x=i,st.y=j,st.b=0;
                 else if(e==3)
                      et.x=i,et.y=j;
             }
          _min=11;
          DFS(st);
          if(_min<=10) printf("%d\n",_min);
          else printf("-1\n");          
    }
    return 0;
}
