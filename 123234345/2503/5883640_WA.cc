#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>
#include<map>
using namespace std;
int main()
{
    map<string,string> mss;
    string sd;
    while(getline(cin,sd),sd.find(" ")!=string::npos)
    {
         string s1,s2;
         istringstream sin(sd);
         sin>>s1>>s2;
         mss[s2]=s1;
         //cout<<s1<<" "<<s2<<endl;
    }
    if(mss[sd]!="") cout<<mss[sd]<<endl;
        else cout<<"eh\n";
    while(cin>>sd)
        if(mss[sd]!="") cout<<mss[sd]<<endl;
        else cout<<"eh\n";
}
