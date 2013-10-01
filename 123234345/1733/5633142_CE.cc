#include<iostream>
#include<map>
using namespace std;
const int MAX=10005;
int n,p;
int pre[MAX],parity[MAX];
map<int,int> numIndex;//map 离散化 
int Find(int x)
{
    if(pre[x]<0) return x;
    int f=Find(pre[x]);
    parity[x]^=parity[pre[x]];
    pre[x]=f;
    return f;
}
bool Query(int a,int b,int odd)
{
     int x=Find(a),y=Find(b);
     if(x==y)
     {
         if(parity[a]^parity[b]==odd) return true;
         return false;
     }
     else
     {
         if(pre[x]<pre[y])
         {
              pre[x]+=pre[y];
              pre[y]=x;
              parity[y]=parity[a]^parity[b]^odd;
         }
         else
         {
             pre[y]+=pre[x];
             pre[x]=y;
             parity[x]=parity[a]^parity[b]^odd;
         }
         return true;
     }
}
void Solve()
{
     int i,x,y,index,idx1,idx2,odd;
     char s[10];
     scanf("%d%d",&n,&p);
     memset(pre,-1,sizeof(pre));
     index=0;
     for(i=0;i<p;i++)
     {
         scanf("%d%d%s",&x,&y,s);
         x--;
         if(numIndex.find(x)==numIndex.end())
               numIndex[x]=index++;
         idx1=numIndex[x];
         if(numIndex.find(y)==numIndex.end())
               numIndex[y]=index++;
         idx2=numIndex[y];
         if(s[0]=='o') odd=1;
         else odd=0;
         if(!Query(idx1,idx2,odd)) break;
     }
     printf("%d\n",i);
}
int main()
{
    Solve();
    return 0;
}





