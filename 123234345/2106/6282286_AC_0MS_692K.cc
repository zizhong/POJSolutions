#include<iostream>
#include<string>
using namespace std;
string rpl[14][2]={{" ",""},{"!!",""},{"(V)","V"},{"(F)","F"},{"!V","F"},{"!F","V"},{"V&V","V"},{"F&F","F"},{"F&V","F"},{"V&F","F"},{"V|V","V"},{"V|F","V"},{"F|V","V"},{"F|F","F"}};
string s;
int main()
{
    int i,t,cnt=1;
    while(getline(cin,s))
    {
         while(1)
         {
              for(i=0;i<14;i++)
                 while((t=s.find(rpl[i][0]))!=string::npos)
                 {
                      s.erase(t,rpl[i][0].length());
                      s.insert(t,rpl[i][1]);
                 }
              if(s.length()==1) break;
         }
         cout<<"Expression "<<cnt++<<": "<<s<<endl;
    }
}
