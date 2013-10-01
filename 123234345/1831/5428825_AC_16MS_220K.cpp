#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
int a[70000];
const double eps=1e-6;
int f=0;
int dfs(int sum,int x,int t,double y)
{
    if(sum>57)
    {
              if(sum&1)
              {
                       int d=dfs((sum-9)/2,1,t+2,1.0);
                       a[t]=3;
                       a[t+1]=6;
                       for(int i=t+2;i<d;i++)
                       a[i]*=2;
                       return  d;
              }
              else
              {       
                       int d=dfs((sum-2)/2,1,t+1,1.0);
                       a[t]=2;
                      // a[t+1]=6;
                       for(int i=t+1;i<d;i++)
                       a[i]*=2;
                       return d;
                  
              }
    }
    if(sum==0)
    {
        if(fabs(y-0)<eps)
        {
                         f=1;
                         return t;
        }   
    }
    if(sum<x||y<0)return 0;
    int d=dfs(sum-x,x,t+1,y-1.0/x);
    a[t]=x;
    if(f)return d;
    if(!f)
    {
          int d=dfs(sum,x+1,t,y);
          return d;
    }
    
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
              int n;
              cin>>n;
              f=0;
              int m=dfs(n,1,0,1.0);
              if(!f)cout<<-1<<endl;
              else
              {
                  cout<<m<<" ";
              for(int i=0;i<m;i++)
              cout<<a[i]<<" ";
              cout<<endl;
              }
              
              
              
    }
    //system("pause");
    return 0;
} 

