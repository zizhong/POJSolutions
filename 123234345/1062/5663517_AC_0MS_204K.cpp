#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 110
int graph[N][N];
int rank[N];
int value[N];
int m, n, len;
bool  findrank( int t )
{
    for( int i= 0; i< t; ++i )
    if( value[i]== t ) return true;    
    return false;
}
int dis( int Rank )
{
    bool visite[N];
    int  result[N];
    rank[0]= Rank;    
    for( int i= 1; i<= n; ++i ) 
    {
        int t= Rank- rank[i];        
        if( t<= m && t>= 0 ) { visite[i]= false;result[i]= graph[0][i];}
        else { visite[i]= true;result[i]= -1; }
    }
    
    visite[0]= true;
    for(int t=1;t<=n;++t)
    {
        int  min= INT_MAX;
        int  k= -1;
        
        for( int i= 0; i<= n; ++i )
        if( !visite[i] && result[i]>= 0 && result[i]< min  )
        {
            min= result[i];
            k= i;
        }
        if( k== -1 ) break;
        
        visite[k]= true;
        for( int i= 1; i<= n; ++i )
        {
            if( !visite[i] &&  graph[k][i]>= 0 && result[k]>= 0 
                        && ( result[k]+ graph[k][i]< result[i] || result[i]== -1 ) )
            result[i]= result[k]+ graph[k][i];
        } 
    }
 
    return result[1];
}

int main()
{
    scanf("%d%d", &m, &n);
    len= 0;
    
    memset( graph, -1, sizeof(int)*N*N );
    
    for( int i= 1; i<= n; ++i )
    {
        int va, ra, nn;
        
        scanf("%d%d%d", &va, &ra, &nn );
        graph[0][i]= va;
        rank[i]= ra;
        
        if( !findrank( ra ) ) value[len++]= ra;
        
        for( int j= 0; j< nn; ++j )
        {
            int a, b;
            scanf("%d%d", &a, &b);
            
            graph[a][i]= b;
        }
    }    
    
    int min= INT_MAX;
    for( int i= 0; i< len; ++i )
        {        
            int t= dis( value[i] );
            
            if( t< min && t!= -1 ) min= t;
        }
        
    printf("%d\n", min );
    
    return 0;
}