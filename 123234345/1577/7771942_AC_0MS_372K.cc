#include<stdio.h>
#include<string.h>
const int N=27;
int node[N],lcd[N],rcd[N],top=-1,n,nn;
char tree[N][N];
void insert(int x,int id)
{
     if(node[id]==-1)
     {
          node[id]=x;
          nn++;
          return ;
     }
     if(x<node[id])
     {
           if(lcd[id]==-1)
           {
               lcd[id]=nn++;
               node[lcd[id]]=x;
               return ;
           }else 
           insert(x,lcd[id]);
     }
     if(node[id]<x)
     {
           if(rcd[id]==-1)
           {
                rcd[id]=nn++;
                node[rcd[id]]=x;
                return ;
           }else insert(x,rcd[id]);
     }
}
void dfs(int id)
{
     if(node[id]==-1) return ;
     putchar('A'+node[id]);
     if(lcd[id]!=-1) dfs(lcd[id]);
     if(rcd[id]!=-1) dfs(rcd[id]);
}
int main()
{
    while(scanf("%s",tree[++top]))
    {
        if(tree[top][0]=='$'||tree[top][0]=='*')
        {
             n=top;
             nn=0;
             top--;
             memset(node,-1,sizeof(node));
             memset(lcd,-1,sizeof(lcd));
             memset(rcd,-1,sizeof(rcd));
             while(top!=-1)
             {
                  for(int i=0;tree[top][i];i++)
                     insert(tree[top][i]-'A',0);
                  top--;
             }
             dfs(0);
             puts("");
        }
        if(tree[n][0]=='$') break; 
    }
}
