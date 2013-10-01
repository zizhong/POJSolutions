#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string ans[13];
int main()
{
     int i;
     ans[0] = "-";
     string temp;
     for(i = 1; i <= 12; ++i)
     {
             temp = "";
             for(int j = 1; j <= int(pow(3.0,double(i - 1))); j++)
             temp += ' ';
             ans[i] = ans[i - 1] + temp + ans[i - 1];
     }
     while(scanf("%d",&i) != EOF)
     {
     cout<<ans[i]<<endl;
     }
     return 0;
}
