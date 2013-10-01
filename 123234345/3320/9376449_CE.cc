#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int N,ind[1000009],a[1000009],total=1000009,t=0;
void solve()
{
    int i,num=0;
    for(i=1;i<=N;i++)
     {
        if(ind[a[i]]==0)
         {
             num++;
             ind[a[i]]=i;
            if(num==t) 
             {
                int* tmp=min_element(&ind[1],&ind[t+1]);
                if(total>i-*tmp+1) total=i-*tmp+1;
                 *tmp=0;num--;
             }
         }
        else
         {
             ind[a[i]]=i;
         }
     }
}
int main()
{
    scanf("%d",&N);
    int i,x;
    map<int,int> mm;  
    for(i=1;i<=N;i++)
     {
         scanf("%d",&x);
         if(mm[x]==0) mm[x]=++t;
         a[i]=mm[x];
     }
     solve();
     printf("%d\n",total);
} 
