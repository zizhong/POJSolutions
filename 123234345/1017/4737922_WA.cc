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
      int box=x6+x5+x4+(x3+3)/4;
      int x2wei=x4*5+7-(x3%4)*2,
          x1wei=5*x5+8-x3;
      if(x2-x2wei>0)
         {
           box=(x2-x2wei+8)/9;
           x1wei+=(36-(x2-x2wei)%9*4);           
         }
      else
          x1wei+=(x2wei-x2)*4;
      if(x1-x1wei>0)
          box+=(x1-x1wei+35)/36;
      cout<<box<<endl;
   }
}
