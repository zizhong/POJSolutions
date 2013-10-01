#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int maxm = 2*5*6*64;
const int maxn = 2*5*6+10;
#define FF(i,A,s) for (int i = A[s] ; i != s ; i = A[i])
struct DancingLinks {
    int R[maxm] , L[maxm] , U[maxm] , D[maxm] , col[maxm] , row[maxm];
    int S[maxn]; bool hash[maxn];
    int ans[maxn];
    int pre , first , sz , NV;
    void init(int n) {
        for ( int i = 0 ; i <= n ; i ++ ) {
            U[i] = i, D[i] = i, S[i] = 0;
            L[i] = i - 1, R[i] = i + 1;
        }
        NV = n , sz = n + 1 , pre = -1 , first = 0;
    }
    void insert(int i, int j) {
        if ( i != pre ) {
            R[sz - 1] = first , L[first] = sz - 1;
            pre = i , first = sz;
        }
        D[U[j]] = sz , L[sz] = sz - 1, R[sz] = sz + 1;
        D[sz] = j, U[sz] = U[j] , U[j] = sz;
        row[sz] = i, col[sz ++] = j , S[j] ++;
    }
    void finish() { R[sz - 1] = first; L[first] = sz - 1; }
    void EXremove(int c) {//del column 
        L[R[c]] = L[c]; R[L[c]] = R[c];
        FF(i , D , c)FF(j , R , i) U[D[j]] = U[j], D[U[j]] = D[j], --S[col[j]];
    }
    void EXresume(int c) {
        FF(i , U , c)FF(j , L , i) ++S[col[j]], U[D[j]] = j, D[U[j]] = j;
        L[R[c]] = c; R[L[c]] = c;
    }
    void remove(int &c) {FF(i , D , c) L[R[i]] = L[i], R[L[i]] = R[i];}
    void resume(int &c) {FF(i , U , c) L[R[i]] = i, R[L[i]] = i;}
    int h(int ret = 0) {
        memset(hash , false , sizeof(bool) * ( NV + 1 ));
        for (int c = R[0] ;  c != 0; c = R[c]) if (!hash[c]) {
            ret ++ , hash[c] = true;
            FF(i , D , c)
                FF(j , R , i)
                hash[col[j]] = true;
        }
        return ret;
    }
    void dfs(int deep,int& lim)
    {
         if(deep+h()>lim) return ;
         if(R[0]==0) { lim=deep; return ;}
         int idx=R[0];
         for(int i=R[0];i!=0;i=R[i])
              if(S[i]<S[idx]) idx=i;
         FF(i, D, idx)
         {
             remove(i);
             FF(j, R, i) remove(j);
             dfs(deep+1,lim);
             FF(j, L, i) resume(j);
             resume(i);
         }
         return ;
    }
}dlx;
bool stk[2*6*6];
int  d[16][16];
int g[64][64];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(stk,true,sizeof(stk));
        memset(d,0,sizeof(d));
        memset(g,0,sizeof(g));
        int n,m;
        scanf("%d%d",&n,&m);
        int stknum=2*n*(n+1)-m,sqnum=0;
        while(m--)
        {
             int x;
             scanf("%d",&x);
             stk[x]=false;
        }
        int cnt=0;
        for(int i=0;i<n+n+1;i++)
        {
             int k=n+(i%2),j=(i+1)%2;
             while(k--)
                 d[i][j]=++cnt,j+=2;
        }
        for(int l=1;l<=n;l++)
        {
             for(int x=0;x<n+1-l;x++)
                 for(int y=0;y<n+1-l;y++)
                 {
                       int sx=1+2*x,sy=1+2*y,ex=sx+2*l-2,ey=sy+2*l-2,flag=0;
                       int st[64]={0},top=0;
                       for(int i=0;i<l;i++)
                             if(!stk[d[sx-1][sy+2*i]]) flag=1;
                             else st[top++]=d[sx-1][sy+2*i];
                       if(flag) continue;
                       for(int i=0;i<l;i++)
                             if(!stk[d[ex+1][sy+2*i]]) flag=1;
                             else st[top++]=d[ex+1][sy+2*i];
                       if(flag) continue;
                       for(int i=0;i<l;i++)
                             if(!stk[d[sx+2*i][sy-1]]) flag=1;
                             else st[top++]=d[sx+2*i][sy-1];
                       if(flag) continue;
                       for(int i=0;i<l;i++)
                             if(!stk[d[sx+2*i][ey+1]]) flag=1;
                             else st[top++]=d[sx+2*i][ey+1];
                       if(flag) continue;
                       ++sqnum;
                       while(top)
                             g[st[--top]][sqnum]=1;
                 }
        }
        if(sqnum==0) {puts("0");continue;}
        dlx.init(sqnum);
        for(int i=1;i<=2*n*(n+1);i++) if(stk[i])
            for(int j=1;j<=sqnum;j++)
                if(g[i][j]) dlx.insert(i,j);
        dlx.finish();
        int ans=stknum;
        dlx.dfs(0,ans);
        printf("%d\n",ans);
    }
}
