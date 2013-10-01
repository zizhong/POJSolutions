#include<iostream>
#include<vector>
#include<sstream>
#include<iterator>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    int g,w;
    cin>>g>>w;
    int i;
    vector < string > girl; 
    for(i=0;i<g;i++)
    {
        string name;
        cin>>name;
        girl.push_back(name);
    }
    getchar();
    for(i=0;i<w;i++)
    {
        int j,k;
        vector<string>wish;
        string s;
        getline(cin,s);
        
         for(j=0;j<s.size();j++)
        {
            if(s[j]=='!') s[j]=' ';
            if(s[j]<='Z'&&s[j]>='A') {
            char c=s[j]-'A'+'a';
            s.replace(j,1,1,c);
            }
        }
       /*for(string::iterator p=s.begin();p!=s.end();p++)
        {
            if(*p=='!') *p=' ';
            if(*p>='A') {char c=*p;s.replace(p,p+1,1,c-'A'+'a');}
        }*/
        istringstream sin(s);
        for(string ss;sin>>ss;wish.push_back(ss)/*,cout<<ss<<endl*/);
        
        bool all=true,first=true;
        bool happy=false;
        bool find[g];
        memset(find,false,sizeof(find));
        for(j=0;j<wish.size();j++)
        {
             for(k=0;k<girl.size();k++)
             {
                 if(wish[j]==girl[k])
                 {
                     all=false;
                     if(find[k]==false)
                     {
                          find[k]=true;
                          /*if(!first) cout<<' ';
                          cout<<girl[k];
                          first=false;*/
                     }
                 }
             }
             if(wish[j]=="beautiful"||wish[j]=="pretty"||wish[j]=="lovely")
                  happy=true;
        }
        if(all) cout<<"All";
        else
        {
            for(k=0;k<girl.size();k++)
               if(find[k])
               {
                   if(!first) cout<<' ';
                   cout<<girl[k];
                   first=false;
               }
        }
        cout<<": ";
        if(wish.size()<10) cout<<"oh"<<endl;
        else
        {
            if(happy) cout<<"xixi\n";
            else cout<<"hehe\n";
        }
    }
}
