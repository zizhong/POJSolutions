#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int  N=1024;
const int INF=0x3fffffff;
typedef int M[N][N];

int k, m, s, t, v;
int ans[N][N], adj[N][N], vis[N], vtx[N], dis[N][N], tp[N][N];

void floyd(M c, M a, M b) {
    int i, j, k;
    for (k = 0; k < v; ++k)
        for (i = 0; i < v; ++i)
            for (j = 0; j < v; ++j)
                if (c[vtx[i]][vtx[j]] > a[vtx[i]][vtx[k]] + b[vtx[k]][vtx[j]])
                    c[vtx[i]][vtx[j]] = a[vtx[i]][vtx[k]] + b[vtx[k]][vtx[j]];
}

void copy(M a, M b) {
    int i, j;
    for (i = 0; i < v; ++i)
        for (j = 0; j < v; ++j) {
            a[vtx[i]][vtx[j]] = b[vtx[i]][vtx[j]];
            b[vtx[i]][vtx[j]] = INF;
        }
}

void BS(int k) 
{
    while (k) 
    {
        if (k & 1) 
        {
            floyd(dis, ans, adj);
            copy(ans, dis);
        }
        floyd(tp, adj, adj);
        copy(adj, tp);
        k >>= 1;
    }
}

int main() 
{
    int i, j, x, y, w;
    scanf("%d %d %d %d", &k, &m, &s, &t);
    for (i = 0; i <= 1001; ++i) {
        for (j = 0; j <= 1001; ++j) {
            adj[i][j] = INF;
            tp[i][j] = INF;
            dis[i][j] = INF;
            ans[i][j] = INF;
        }
        ans[i][i] = 0;
    }
    v = 0;
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < m; ++i) {
        scanf("%d %d %d", &w, &x, &y);
        if (!vis[x]) {
            vis[x] = 1;
            vtx[v++] = x;
        }
        if (!vis[y]) {
            vis[y] = 1;
            vtx[v++] = y;
        }
        if (adj[x][y] > w)
            adj[x][y] = adj[y][x] = w;
    }
    BS(k);
    printf("%d\n", ans[s][t]);
}
