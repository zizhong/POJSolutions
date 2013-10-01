#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack< string > forw;
    stack< string > backw;
    string com,cur;
    cur="http://www.acm.org/";
    while(cin>>com&&com!="QUIT")
    {
       if(com=="VISIT")
       {         
          backw.push(cur);
          cin>>cur;
          cout<<cur<<endl;
          while(!forw.empty())
             forw.pop();          
       }
       if(com=="BACK")
          if(backw.empty()) cout<<"Ignored\n";
          else
          {
              forw.push(cur);
              cur=backw.top();
              cout<<cur<<endl;
              backw.pop();
          }
       if(com=="FORWARD")
         if(forw.empty()) cout<<"Ignored\n";
         else
         {
             backw.push(cur);
             cur=forw.top();
             cout<<cur<<endl;
             forw.pop();
         }
    }
}
