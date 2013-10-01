#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   int k=0,q=0,c=0,x=-1,n;
   cin>>n;
   for(int i=0;i<n;i++)
   {   x=-1;
       int a,b;char ch,c1,c2;
       cin>>c1>>a>>c2>>b;
       
       if(c1==c2&&a==b)
       {
          cout<<"0 0 0 0\n";
         break;
       }
       int num1=abs(a-b),num2=abs(c1-c2);
       if(c1==c2||a==b)
       {
          q=1;
          c=1;
          k=(num1>num2?num1:num2);       
       }
       else
       if(num1==num2)
       {
          x=1;
          k=num1;
          q=1;
          c=2;
       }
       else
       {
         q=2;
         c=2;
         int t1=num1+num2,
             t2=abs(a+num1-b)>abs(a-num1-b)?abs(a-num1-b):abs(a+num1-b);
         k=t1>t2?t2:t1;
       }
    cout<<k<<' '<<q<<' '<<c<<' ';
   if(x==-1) cout<<"Inf"<<endl;
   else cout<<x<<endl;
   }
   
 
}
