#include<iostream>
#include<queue>
using namespace std;
const int NMAX=200001;
bool visited[NMAX];
int times[NMAX]={0};
void visit(int y,int x,queue<int > & q)
{
    if(visited[x]||x>100000||x<0) return ;
    visited[x]=true;
    times[x]=times[y]+1;
    q.push(x);
}
int main()
{
   int n,k;
   cin>>n>>k;
   if(n==k)
   {
   cout<<"0\n";
   return 0;
   }
   queue< int > q;
   q.push(n);
   while(visited[k]==false)
   {
     int x=q.front();
     visited[x]=true;
     q.pop();
     visit(x,x-1,q);
     visit(x,x+1,q);
     visit(x,2*x,q);
   }
   cout<<times[k]<<endl;}
