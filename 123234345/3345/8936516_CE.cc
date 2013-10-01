#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
const int maxint=0x7FFFFFFF;
int n, m;
 
vector <int> child[300];
vector <string> child_name[300];
string name[300];
int dia[300];
int after[300];
 
int f[300][300];
int used[300];
int p[300];
int q[300];
 
int dfs(int x)
{
    int ret = 0;
    if (used[x]) return after[x];
    for (int i = 0; i < child[x].size(); i++)
        ret += dfs(child[x][i]);
    
    for (int i = 0; i <= n; i++) p[i] = maxint;
    p[0] = 0;
    for (int i = 0; i < child[x].size(); i++)
    {
        for (int j = 0; j <= n; j++) q[j] = maxint;
        for (int k = 0; k <=n; k++) if (p[k] != maxint)
        {
            for (int j = 0; k + j <= n; j++) if (f[child[x][i]][j] != maxint)
                q[k + j] = min(p[k] + f[child[x][i]][j],q[k+j]);
        }
        for (int j = 0; j <= n; j++) p[j] =min(p[j] , q[j]);
    }
    used[x] = 1;
    after[x] = ret + 1;
    p[after[x]] <?= dia[x];
    memcpy(f[x], p, sizeof(p));
    
    return after[x];
}
 
int in_deg[300];
 
int main()
{
    char s[1000];
    while (gets(s), strcmp(s, "#") != 0)
    {
        if (strcmp(s, "") == 0) continue;
        stringstream ss(s);
        ss >> n >> m;
        for (int i = 0; i < n; i++)
        {
            child_name[i].clear();
            child[i].clear();
            char s[100000];
            scanf("%s%d", s, &dia[i]);
            name[i] = s;
            gets(s);
            stringstream ss(s);
            string t;
            while (ss >> t)
                child_name[i].push_back(t);
        }
        memset(in_deg, 0, sizeof(in_deg));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < child_name[i].size(); j++)
            {
                for (int k = 0; k < n; k++) if (child_name[i][j] == name[k])
                {
                    child[i].push_back(k);
                    in_deg[k]++;
                    break;
                }
            }
        child[n].clear();
        for (int i = 0; i < n; i++) if (in_deg[i] == 0)
            child[n].push_back(i);
        dia[n] = maxint;
            
        memset(used, 0, sizeof(used));
        memset(after, 0, sizeof(after));
        memset(f, 0, sizeof(f));
        dfs(n);
        int ans = maxint;
        for (int i = m; i <= n; i++) ans =ans<f[n][i]?ans:f[n][i];
        printf("%d\n", ans);
    }
    return 0;
}
