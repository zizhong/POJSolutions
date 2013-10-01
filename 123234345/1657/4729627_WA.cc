#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {  
       int a,b;char c1,c2;
       cin>>c1>>a>>c2>>b;       
       if(c1==c2&&a==b)
       {
          cout<<"0 0 0 0\n";
        continue;
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
        if(abs(x-y)!=0)
         cout<<" Inf\n";                   
       else if(x==y) cout<<" 1\n";
       else  cout<<" 2\n";
   }
}
