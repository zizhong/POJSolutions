#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   int k=0,q=0,c=0,x=-1,n;
   cin>>n;
   for(int i=0;i<n;i++)
   {   k=0,q=0,c=0,x=-1;
       int a,b;char ch,c1,c2;
       cin>>c1>>a>>c2>>b;       
       if(c1==c2&&a==b)
       {
          cout<<"0 0 0 0\n";
         break;
       }
       
       int num1=abs(a-b),num2=abs(c1-c2);
       if(num1>num2) 
            k=num1;
       else   
            k=num2;
       if(num1==0||num2==0)
          c=1,q=1;
       else if(num1==num2)
          x=1,q=1,c=2;
       else
          c=2,q=2;
       if((num1%2==num2%2)&&(num1!=num2))
           x=2; 
               
       cout<<k<<' '<<q<<' '<<c<<' ';
       if(x!=1&&x!=2) cout<<"Inf"<<endl;
         else cout<<x<<endl;
   }
   
 
}
