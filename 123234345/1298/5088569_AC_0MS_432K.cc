#include<iostream>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    while(s!="ENDOFINPUT")
    {
       if(s=="START")
       {
          getline(cin,s);
          while(s!="END")
          {
          int i;
          for(i=0;i<s.size();i++)
             if(s[i]>='A'&&s[i]<='Z')
               if(s[i]-5>='A') s[i]-=5;
               else s[i]+=21;
          cout<<s<<endl;
          getline(cin,s);
          }
       }
       getline(cin,s);
    }
}
