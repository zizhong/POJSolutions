#include <stdio.h>
#include <string.h>
#define MAXN 30
#define MAXE 100
#define INF 0x3fffffff
 
struct node
{
    int v, d, next; //
}pot[MAXE];
int g[MAXN], pl, r[MAXN], t[MAXN], c[MAXN];
int dis[MAXN], visit[MAXN], queue[MAXN], ans;
 
int spfa( int n, int s ) //µãµÄ¸öÊý£¬Ô´µã£¬»ãµã
{
    int top, tail, u, v, k;
    for ( u = 1; u <= 24; ++u )
        dis[u] = -INF;
    memset( visit, 0, sizeof( visit ) );
    memset( c, 0, sizeof( c ) );
    dis[s] = 0; top = 0; tail = 1;
    queue[0] = s; visit[s] = 1;
    while ( top != tail ) //Ñ­»·¶ÓÁÐ
    {
        u = queue[top++]; visit[u] = 0;
        if ( top == n ) top = 0;
        for ( k = g[u]; k != -1; k = pot[k].next )
        {
            v = pot[k].v;
            if ( dis[v] - pot[k].d < dis[u] )
            {
                dis[v] = dis[u] + pot[k].d;
                if ( !visit[v] )
                {
                    queue[tail] = v; visit[v] = 1;
                    if ( ++c[v] > n ) return 0;
                    if ( ++tail == n ) tail = 0;
                }
            }
        }
    }
    return ( dis[24] == ans );
}
 
void addEdge( int u, int v, int w )
{
    pot[pl].next = g[u];
    pot[pl].v = v; pot[pl].d = w;
    g[u] = pl++;
}
 
void ConstructGraph()
{
    int i;
    memset( g, -1, sizeof( g ) );
    pl = 0;
    for ( i = 1; i <= 16; ++i )
        addEdge( i, i+8, r[i+8] );
    for ( i = 1; i <= 8; ++i )
        addEdge( i+16, i, r[i]-ans );
    for ( i = 1; i <= 24; ++i )
        addEdge( i-1, i, 0 );
    for ( i = 1; i <= 24; ++i )
        addEdge( i, i-1, -t[i] );
     //Õâ¾ä¸Ð¾õÓ¦¸ÃÊÇaddEdge( 24, 0, -ans )£¬¼´S24-S0<=ans£¬µ«ÊÇ´íÁË£¬Ò²ÐíÌâÄ¿ÖÐ¡°Note that there can be
         //more cashiers than the least number needed for a specific slot. ¡±ÊÇÒ»¸öÌáÐÑ°É¡£¡£¡£
    addEdge( 0, 24, ans );
}
 
int main()
{
    int cases, m, i, x;
    scanf( "%d", &cases );
    while ( cases-- )
    {
        memset( t, 0, sizeof( t ) );
        for ( i = 1; i <= 24; ++i )
            scanf( "%d", &r[i] );
        scanf( "%d", &m );
        for ( i = 0; i < m; ++i )
        {
            scanf( "%d", &x );
            t[x+1]++;
        }
        ans=m;
        ConstructGraph();
            if ( !spfa( 25, 0 ) ){printf( "No Solution\n");continue;}
        for ( ans = 0; ans <= m; ++ans )
        {
            ConstructGraph();
            if ( spfa( 25, 0 ) ) break;
        }
        if ( ans <= m )
            printf( "%d\n", ans );
        else
            printf( "No Solution\n");
    }
    return 0;
}