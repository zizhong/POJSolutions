#include<iostream>
#include<stdio.h>
using namespace std;
const int N=11;
int n,m,sx,sy,g[N][2],f[N];
int Abs(int a){return a>0?a:-a;}
int dis(int x1,int y1,int x2,int y2){return Abs(x1-x2)+Abs(y1-y2);} 
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int nb;
        scanf("%d%d%d%d%d",&n,&m,&sx,&sy,&nb);
        for(int i=0;i<N;i++) f[i]=i;
        for(int i=0;i<nb;i++) scanf("%d%d",&g[i][0],&g[i][1]);
        int min=0xfffffff;
        do
        {
            int ans=dis(g[f[0]][0],g[f[0]][1],sx,sy)+dis(g[f[nb-1]][0],g[f[nb-1]][1],sx,sy);
            for(int i=0;i<nb-1;i++)
                    ans+=dis(g[f[i]][0],g[f[i]][1],g[f[i+1]][0],g[f[i+1]][1]);
            if(ans<min) min=ans;
        }while(next_permutation(f,f+nb));
        printf("The shortest path has length %d\n",min);        
    }
}
