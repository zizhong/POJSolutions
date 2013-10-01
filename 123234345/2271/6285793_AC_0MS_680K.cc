#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
   
    string str,s;
    int len=0;
    while(cin>>str)
    {
         if(str=="<br>")
         {
              cout<<s<<endl;
              s="";
              len=0;
         }
         else if(str=="<hr>")
         {
              if(len) cout<<s<<endl;
              len=0,s="";
              cout<<"--------------------------------------------------------------------------------"<<endl;
         }else
         {
              if(len==0)
              {
                        len=str.length();
                        s=str;
              }else
              {
                   int sum=len+1+str.length();
                   if(sum>80)
                   {
                             cout<<s<<endl;
                             len=str.length(),s=str;
                   }else
                        len=sum,s=s+" "+str;
              }              
         }
    }
    if(len) cout<<s<<endl;
}
