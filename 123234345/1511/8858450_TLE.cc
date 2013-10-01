#include "stdio.h"
#define INF (((__int64)1)<<60)
#define NUM 1000001
struct Node{
 int no,dis;
 Node* next;
};
struct hNode{
 int no;
 __int64 dis;
};

Node * node;
hNode hnode[NUM];
int hs;
int P,Q,t;
void Input();
void push(hNode k);
void pop();
__int64 Dijkstra();
void reverse();
bool operator<(const hNode& a,const hNode& b)
{
 return a.dis<b.dis;
}
int main(int argc, char* argv[])
{
 scanf("%d",&t);
 while (t--)
 {
  Input();
  __int64 x=Dijkstra();
  reverse();
  x+=Dijkstra();
  printf("%I64d\n",x);
  Node* p;
  for(int i=1;i<=P;++i)
  {
   p=node[i].next;
   while (p!=NULL)
   {
    Node* s = p;
    p=p->next;
    delete s;
   }
  }
  delete []node;
 }
 return 0;
}
void Input()
{
 int i;
 scanf("%d %d",&P,&Q);
 node= new Node[P+1];
 for(i=0;i<P+1;++i)
  node[i].next=NULL;
 for(i=0;i<Q;++i)
 {
  int x,y,dis;
  scanf("%d %d %d",&x,&y,&dis);
  Node* n=new Node;
  n->dis=dis;
  n->no=y;
  n->next=node[x].next;
  node[x].next=n;
 }
}
void push(hNode k)
{
 ++hs;
 int i=hs;
 while ( i > 1 && k < hnode[ i>>1 ])
 {
  hnode[i] = hnode[i>>1];
  i>>=1;
 }
 hnode[i]= k;
}
void pop()
{
 int i=1,j=2;
 while ( j< hs )
 {
  if(j+1 < hs && hnode[j+1] < hnode[j]) ++j;
  if( hnode[j] < hnode[hs])
  {
   hnode[i]=hnode[j];
   i=j;
   j<<=1;
  }
  else 
   break;
 }
    hnode[i] = hnode[hs--];
}

__int64 Dijkstra()
{
   __int64* dis = new __int64[P+1];
   int i;
   hNode now;
   for(i=1;i<=P;++i)
    dis[i] = INF;  
   dis[1]=0;
   now.dis=0;now.no=1;
   push(now);
   while (1)
   {
    while (hs > 0 && dis[ hnode[1].no ] < hnode[1].dis)
       pop();
    if(hs==0) break;
       now=hnode[1];
    pop();
    Node* p;
    for(p=node[now.no].next;p!=NULL;p=p->next)
    {
     if( dis[ p->no ] > dis[now.no] + p->dis)
     {
      dis[p->no] = dis[now.no] + p->dis;
      hNode k;
      k.dis=dis[p->no];
      k.no=p->no;
      push(k);
     }
    }
   }
   __int64 ans=0;
   for(i=1;i<=P;++i)
    ans+=dis[i];
   delete []dis;
   return ans;
}
void reverse()
{
 int i;
    Node* k=new Node[P+1];
 for( i=1;i<=P;++i)
  k[i].next=NULL;
 for( i=1;i<=P;++i)
 {
  Node* q=node[i].next;
  Node* s;
  for(;q!=NULL;q=q->next)
  {
   s=new Node;
   s->no=i;
   s->dis=q->dis;
   s->next = k[q->no].next;
   k[q->no].next=s;
  }
 }
 for(i=1;i<=P;++i)
 {
  Node* q,* s;
  for(q=node[i].next;q!=NULL;)
  {
   s=q;
   q=q->next;
   delete s;
  }
  node[i].next=NULL;
 }
 delete []node;
 node = k;
}
