#include <iostream>
#include <map>
#include<cstring>
#include<cstdio>
using namespace std;

const int MAXP = 10;
const int MAXL = 10;
const int MAXN = 50;
const int MAXNODS = MAXP * MAXL + 1;
const int base = (int)1e9;

int size, n, a, b;
int trie[MAXNODS][MAXN];
int queue[MAXNODS], suffix[MAXNODS];
bool danger[MAXNODS], visited[MAXNODS];
char letter[MAXP + 1];
int counter[2][MAXNODS][21], ans[21];

map<char, int>dic;

void Build_Trie()
{
    int t, len, p = 0;
    len = strlen(letter);
    for (int i = 0; i < len; i++)
    {
        t = dic[letter[i]];
        if (trie[p][t] == 0)  trie[p][t] = ++size;
        p = trie[p][t];
        if (danger[p]) break;
    }
    danger[p] = true;
}

void Build_Graph()
{
    int head = 1, tail = 0;
    queue[0] = 0;
    for(int i = 0; i < n; i++)
        if (trie[0][i]) queue[++tail] = trie[0][i];    // ¸ù½ÚµãËùÓÐ×Ó½ÚµãµÄºó×º½áµã¾ùÎª¸ù½Úµã
    while (head <= tail)
    {
        danger[queue[head]] |= danger[suffix[queue[head]]];    //ºó×º½áµãÎªÎ£ÏÕ½Úµã£¬¸Ã½ÚµãÒ²ÎªÎ£ÏÕ½Úµã
        if (!danger[queue[head]])
        {
            for(int i = 0; i < n; i++)
            {
                if (trie[queue[head]][i] == 0)
                    trie[queue[head]][i] = trie[suffix[queue[head]]][i];//Èç¹û²»´æÔÚiº¢×Ó£¬ÔòÖ¸Ïòºó×º½áµãµÄiº¢×Ó
                else
                {
                    queue[++tail] = trie[queue[head]][i];
                    suffix[queue[tail]] = trie[suffix[queue[head]]][i];//¼ÆËãºó×º½áµã
                }
            }
        }
        ++head;
    }
}

void add(int *p, int * q)
{
    if (p[0] < q[0]) p[0] = q[0];
    for (int k = 1; k <= p[0]; k++)
    {
        p[k] += q[k];
        p[k + 1] += (p[k] / base);
        p[k] %= base;
    }
    if (p[p[0] + 1]) p[0]++;
}

void bfs(int node)
{
    if (visited[node])return;
    visited[node] = true;
    for (int i = 0; i < n; i++)
    {
        if (!danger[trie[node][i]])
        {
            add(counter[a][trie[node][i]], counter[b][node]);
            bfs(trie[node][i]);
        }
    }
}

void bfs_ans(int node)
{
    if (visited[node]) return;
    visited[node] = true;
    add(ans, counter[a][node]);
    for (int i = 0; i < n; i++)
        if (!danger[trie[node][i]]) bfs_ans(trie[node][i]);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int p, m, ch, i;

    memset(danger, 0, sizeof(danger));
    memset(trie, 0, sizeof(trie));

    scanf("%d %d %d\n", &n, &m, &p);
    for (i = 0; i < n; i++)scanf("%c", &ch), dic[ch] = i;
    for (i = 0; i < p; i++)scanf("%s", letter), Build_Trie();
    Build_Graph();

    a = 1, b = 0;
    counter[1][0][0] = counter[1][0][1] = 1;
    for (i = 0; i < m; i++)
    {
        swap(a, b);
        memset(visited, 0, sizeof(visited));
        memset(counter[a], 0, sizeof(counter[a]));
        bfs(0);
    }
    memset(visited, 0, sizeof(visited));
    memset(ans, 0, sizeof(ans));
    bfs_ans(0);
    printf("%d", ans[ans[0]]);
    for (i = ans[0] - 1; i > 0; i--)
        printf("%.9d", ans[i]);
    printf("\n");
    return 0;
}
