#include<iostream>
using namespace std;
int main()
{
   while(1)
   {
      string s;
      getline(cin,s);
      if(s=="#") break;
      int i=0;
      for(i=0;i<s.size();i++)
      {
          if(s[i]==' '||s[i]=='!'||s[i]=='$'||s[i]=='%'||s[i]=='('||s[i]==')'||s[i]=='*')
              cout<<'%'<<hex<<int(s[i]);
          else cout<<s[i];
      }
      cout<<endl;
   }
}
