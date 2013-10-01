#include<stdio.h>
#include<string.h>
#define N 5005
#define M 50000

struct Node
{
       int j;
       Node* next;
};

Node mem[M];
int memp;

void AddEdge(Node *e[],int i,int j)
{
     Node *p=&mem[memp++];
     p->j=j;
     p->next=e[i];
     e[i]=p;
}

int g_DFS_First;
void DFS_conn(Node*e[],int i,int mark[],int f[],int *nf)
{
     Node *p;
     if(mark[i]) return ;
     mark[i]=1;
     if(!g_DFS_First) f[i]=*nf;
     for(p=e[i];p!=NULL;p=p->next)
         DFS_conn(e,p->j,mark,f,nf);
     if(g_DFS_First) f[(*nf)++]=i;
     
}
int connection(Node* e[],int n,int con[])
{
    int i,j,k,ncon,mark[N],time[N],ntime;
    Node *re[N],*p;
    
    memset(re,0,sizeof(re));
    for(k=0;k<n;k++)
    {
        for(p=e[k];p!=NULL;p=p->next)
            AddEdge(re,p->j,k);
    }
    
    g_DFS_First=1;
    memset(mark,0,sizeof(mark));
    memset(time,0,sizeof(time));
    ntime=0;
    for(i=0;i<n;i++)
       if(!mark[i])
          DFS_conn(e,i,mark,time,&ntime);
          
    g_DFS_First=0;
    memset(mark,0,sizeof(mark));
    memset(con,0,sizeof(con));
    ncon=0;
    for(i=n-1;i>=0;i--)
      if(!mark[time[i]])
         DFS_conn(re,time[i],mark,con,&ncon),ncon++;
    return ncon;  
}
Node *e[N];
int con[N],ncon,d[N];
int n,m;
int main()
{
    int i,j,k,x,y;
    Node* p;
    while(scanf("%d",&n)&&n)
    {
         memp=0;
         memset(e,0,sizeof(e));
         scanf("%d",&m);
         for(k=0;k<m;k++)
         {
             scanf("%d%d",&i,&j);i--,j--;
             AddEdge(e,i,j);
         }
         ncon=connection(e,n,con);
         memset(d,0,sizeof(d));
         for(i=0;i<n;i++)
         {
            x=con[i];
            for(p=e[i];p!=NULL;p=p->next)
            {
               y=con[p->j];
               if(x!=y) d[x]++;
            }
         }
         j=0;
         for(i=0;i<n;i++)
         {
             k=con[i];
             if(d[k]==0)
             {
                if(j) printf(" ");
                j=1;
                printf("%d",i+1);
             }
         }
         printf("\n");
    }
}