#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {         
              int maxa=0;
              int maxb=0;
              int t=0;
              int a,b;
              int w=0;int e=0;
              cin>>a>>b;
              while(a!=-1&&b!=-1)
              {    
                   if(w+a>n)
                   {
                            maxa=max(maxa,w);
                            w=0;
                            maxb+=e;
                            e=b;
                            
                            w+=a;
                            
                   }
                   else
                   {
                       w+=a;
                       if(b>e)e=b;
                   }
                   cin>>a>>b;            
              }
               maxa=max(maxa,w);
               maxb+=e;
              cout<<maxa<<" x "<<maxb<<endl;
              
               cin>>n;
    }
} 


