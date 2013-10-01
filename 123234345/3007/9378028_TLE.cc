#include<cstdio>
#include<string>
#include<map>
#include<iostream>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
          map<string,int> mp1;
          mp1.clear();
          string str;
          cin>>str;
          mp1[str]=1;
          int ans=1;
          for(int i=0;i<str.size()-1;i++)
          {
                for(int k=1;k<=7;k++)
                {
                     string s1=str.substr(0,i+1);
                     string s2=str.substr(i+1);
                     if(k&1)
                     {
                            swap(s1,s2);
                     }
                     if(k&2)
                     {
                            int len=s1.size();
                            for(int i=0;i<len/2;i++)
                                 swap(s1[i],s1[len-1-i]);
                     }
                     if(k&4)
                     {
                            int len=s2.size();
                            for(int i=0;i<len/2;i++)
                                 swap(s2[i],s2[len-1-i]);
                     }
                     string tmp=s1+s2;
                     if(mp1.find(tmp)==mp1.end())
                     {
                          ans++;
                          mp1[tmp]=1;
                     }
                }
          }
          cout<<ans<<endl;
    }
}
