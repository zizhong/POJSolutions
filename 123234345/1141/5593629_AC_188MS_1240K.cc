#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int maxint = 0x7FFFFFFF;
const int maxn = 110;

char s[maxn];
int len;

int f[maxn][maxn];
string ans[maxn][maxn];

void dp()
{
    memset(f, 0, sizeof(f));
    for (int i = 0; i < len; i++)
        for (int j = i; j < len; j++)
        {
            f[i][j] = maxint;
            ans[i][j] = "";
        }
    for (int i = len - 1; i >= 0; i--)
        for (int j = i; j < len; j++)
            if (i == j)
            {
                f[i][j] = 1;
                if (s[i] == '(') ans[i][j] = "()";
                if (s[i] == ')') ans[i][j] = "()";
                if (s[i] == '[') ans[i][j] = "[]";
                if (s[i] == ']') ans[i][j] = "[]";
            }
            else
            {
                if (j > i)
                {
                    if ((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']'))
                    {
                        if (f[i + 1][j - 1] < f[i][j])
                        {
                            f[i][j] = f[i + 1][j - 1];
                            ans[i][j] = s[i] + ans[i + 1][j - 1] + s[j];
                        }
                    }
                }
                for (int k = i; k < j; k++)
                {
                    if (f[i][k] + f[k + 1][j] < f[i][j])
                    {
                        f[i][j] = f[i][k] + f[k + 1][j];
                        ans[i][j] = ans[i][k] + ans[k + 1][j];
                    }
                }
            }
}

int main()
{
    while (gets(s) != NULL)
    {
        len = strlen(s);
        dp();
        if(len>0)
          cout << ans[0][len - 1] << endl;
        else puts("");
    }
}
