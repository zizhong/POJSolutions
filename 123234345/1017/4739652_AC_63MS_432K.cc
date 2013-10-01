#include<iostream>
using namespace std;
int main()
{
   int x1,x2,x3,x4,x5,x6;
   while(1)
   {
      cin>>x1>>x2>>x3>>x4>>x5>>x6;
      if(!(x1||x2||x3||x4||x5||x6))
         break;
      int u[4]={0,5,3,1};
      int box=x6+x5+x4+(x3+3)/4;
      int x2wei=x4*5+u[x3%4],
          x1wei=0;
      if(x2-x2wei>0)     
           box+=(x2-x2wei+8)/9;                  
      x1wei=36*box-36*x6-25*x5-16*x4-9*x3-4*x2;
      if(x1-x1wei>0)
          box+=(x1-x1wei+35)/36;
      cout<<box<<endl;
   }
}
