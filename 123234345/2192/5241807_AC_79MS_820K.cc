#include <iostream>
#include <cstring>
using namespace std;

const int N = 202;

char str1[N], str2[N], result[N * 2];
char hash[N][N];
int len1, len2, lenr;

int dfs(int rr,int s1, int s2)
{
    if(rr == lenr)
        return 1;
    if(hash[s1][s2])
        return 0;
    hash[s1][s2] = 1;
    if(s1 < len1)
    {
        if(result[rr] == str1[s1] && dfs(rr + 1, s1 + 1, s2))
            return 1;
    }
    if(s2 < len2)
    {
        if(result[rr] == str2[s2] && dfs(rr + 1, s1, s2 + 1))
            return 1;
    }
    return 0;
}

int main()
{
   int n, cc;
   while(cin>>n)
   {
       cc = 1;
        while(n--)
        {
            cin>>str1>>str2>>result;
            len1 = strlen(str1);
            len2 = strlen(str2);
            lenr = len1 + len2;
            memset(hash,0,sizeof(hash));
            cout<<"Data set "<<cc++<<": ";
            if(dfs(0, 0, 0))
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
   }
   return 0;
}