#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int cmp(char c1,char c2)
{
    if(tolower(c1)==tolower(c2)) return c1<c2;
    return tolower(c1)<tolower(c2);
}
int main()
{
    int n;
    cin>>n;
    string str;
    while(n--)
    {
       cin>>str;
       sort(str.begin(),str.end(),cmp);
       cout<<str<<endl;
       while(next_permutation(str.begin(),str.end(),cmp))
          cout<<str<<endl;
    }
}
