#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define clr(a) memset(a,0,sizeof(a))
#define MAX(a,b) ((a)>(b)?(a):(b))

#define N 10005
#define M 50005
int pre[N];
struct Node
{
     int j;
     Node* next;
};
Node mem[M*2];
int memp;

void addEdge(Node *e[],int i,int j)
{
     Node *p=&mem[memp++];
     p->next=e[i];
     p->j=j;
     e[i]=p;
}

int g_DFS_First;

void DFS_conn(Node*e[],int i,int mark[],int f[],int *nf)
{
     if(mark[i]) return ;
     Node *p;
     mark[i]=1;
     if(!g_DFS_First) f[i]=*nf;
     for(p=e[i];p;p=p->next)
          DFS_conn(e,p->j,mark,f,nf);
     if(g_DFS_First) f[(*nf)++]=i;
}

int Connection(Node*e[],int n,int con[])
{
    int i,j,k,mark[N],time[N],ncon,ntime;
    Node *p,*re[N];
    clr(re);
    for(i=0;i<n;i++)
       for(p=e[i];p;p=p->next)
          addEdge(re,p->j,i);
    
    g_DFS_First=1;
    clr(mark),clr(time),ntime=0;
    for(i=0;i<n;i++)
       if(!mark[i]) DFS_conn(e,i,mark,time,&ntime);
    
    g_DFS_First=0;
    clr(mark),clr(con),ncon=0;
    for(i=n-1;i>=0;i--)
       if(!mark[time[i]]) DFS_conn(re,time[i],mark,con,&ncon),ncon++;
    return ncon;
}

int ShrinkConnection(Node*e[],int n,Node *ce[],int con[])
{
    int i,j,k,m;
    Node * p,* q;
    m=Connection(e,n,con);
    
    for(i=0;i<m;i++) ce[i]=NULL;
    
    for(k=0;k<n;k++)
    {
        for(i=con[k],p=e[k];p;p=p->next)
        {
            for(j=con[p->j],q=ce[i];q;q=q->next)
                 if(q->j==j) break;
            if(q==NULL&&i!=j) addEdge(ce,i,j);
        }
    }
    return m;
}
int Find(int i)
{
    int r=i;
    while(pre[r]>0) r=pre[r];
    while(r!=i)
    {
        int t=pre[i];
        pre[i]=r;
        i=t;
    }
    return r;
}
int Union(int a,int b)
{
    int r1=Find(a),r2=Find(b);
    int temp=pre[r1]+pre[r2];
    if(pre[r1]>pre[r2])
        pre[r1]=r2,pre[r2]=temp;
    else
        pre[r2]=r1,pre[r1]=temp;
}
int CNT(int n)
{
    int x=Find(1),i;
    for(i=2;i<=n;i++)
        if(Find(i)!=x) break;
    if(i<=n) return 0;
    return 1;
}
int main()
{
    int i,j,k;
    int n,m,con[N],dout[N],din[N];
    Node *e[N],*ce[N],*p;
    
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memp=0;
        clr(e);
        memset(pre,-1,sizeof(pre));
        for(i=0;i<m&&scanf("%d%d",&j,&k);i++)
        {
              addEdge(e,j-1,k-1);
              if(Find(j)!=Find(k)) Union(j,k);
        }
        m=ShrinkConnection(e,n,ce,con);
        
        clr(din),clr(dout);
        for(i=0;i<m;i++)
            for(p=ce[i];p;p=p->next)
                din[p->j]++,dout[i]++;
                
        int mi=-1;
        for(i=0;i<m;i++)
            if(dout[i]==0)
            {
                if(mi==-1) mi=i;
                else break;
            }
            
        if(!CNT(n)||i<m) printf("0\n");
        else
        {
            int num=0;
            for(i=0;i<n;i++)
               if(con[i]==mi) num++;
            printf("%d\n",num);
        }
        
    }
}
