#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    sort(s.begin(),s.end());   
    cout<<s<<endl;
    while(next_permutation(s.begin(),s.end()))
    {
        cout<<s<<endl;
    }
}
