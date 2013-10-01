#include<iostream>
#include<queue>
#define MAXSIZE 30010
using namespace std;

int main()
{
       int i,j,count,index,n,m;
       int a[MAXSIZE],b[MAXSIZE];
       while(cin>>n>>m)
       {    
              priority_queue <int , deque <int> , less <int> > big;
              priority_queue <int , deque <int> , greater <int> > small;
              for(i=1;i<=n;i++)  cin>>a[i];
              for(j=1;j<=m;j++)  cin>>b[j];
              i=1;
              count=1;
              index=1;
              while(count<=m)
              {
                     for(;i<=b[index];i++)          
                     {
                            small.push(a[i]);           
                            big.push(small.top());
                            small.pop();
                            small.push(big.top());
                            big.pop();
                     }    
                     big.push(small.top());
                     small.pop();
                     cout<<big.top()<<endl;
                     count++;
                     index++;
              }
       }
}
