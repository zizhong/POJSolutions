#include<stdio.h>
#include<stdlib.h>
const int N=5100,M=51000;
struct node
{
       int num;
       struct node *next;
};
node *newNode(int num)
{
     node *t=new node;
     t->num=num,t->next=NULL;
     return t;
}
node *arrf[N],*arrb[N],*endf[N],*endb[N];
int n,m,max;
int forward[N],backward[N];
int inf[N],endp[M],stp[M];
void in()
{
     scanf("%d%d",&n,&m);
     int i,x,y;
     for(i=1;i<=m;i++)
     {
         scanf("%d%d",&x,&y);
         inf[y]++;
         stp[i]=x,endp[i]=y;
         if(arrf[x]==NULL) arrf[x]=newNode(y),
                           endf[x]=arrf[x];
         else endf[x]->next=newNode(y),
              endf[x]=endf[x]->next;
         if(arrb[y]==NULL) arrb[y]=newNode(x),
                           endb[y]=arrb[y];
         else endb[y]->next=newNode(x),
              endb[y]=endb[y]->next;
     }
}
void deal()
{
     int i;
     node *p;
     forward[n]=1;
     for(i=n-1;i>=1;i--)
     {
         p=arrf[i];
         while(p)
         {
             forward[i]+=forward[p->num];
             p=p->next;
         }
     }
     for(i=1;i<=n;i++)
         if(!inf[i]) backward[i]=1;
     for(i=1;i<=n;i++)
     {
         p=arrb[i];
         while(p)
            backward[i]+=backward[p->num],
            p=p->next;
     }
     for(i=1;i<=M;i++)
         if(forward[endp[i]]*backward[stp[i]]>max)
             max=forward[endp[i]]*backward[stp[i]];
}
int main()
{
    in();
    deal();
    printf("%d\n",max);
}
