#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   int k=0,q=0,c=0,x=-1,n;
   cin>>n;
   for(int i=0;i<n;i++)
   {  
       int a,b;char ch,c1,c2;
       cin>>c1>>a>>c2>>b;       
       if(c1==c2&&a==b)
       {
          cout<<"0 0 0 0\n";
         break;
       }
       
       int x=abs(a-b),y=abs(c1-c2);
       
       if(x>y) cout<<x;
       else  cout<<y;
       if(x==0||y==0||x==y)
          cout<<" 1";
       else  cout<<" 2";
       if(x==0||y==0) 
        cout<<" 1";
       else  cout<<" 2";
       if(x==y) cout<<" 1\n";
       else if(abs(x-y)==0)
        cout<<" 2\n";
       else cout<<" Inf\n";                   
       
   }
}
