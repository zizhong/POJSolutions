#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
const int N=16;
const int maxm = (4*N*N+10)*(N*N*N+10);
const int maxn = N*N*N+10;
#define FF(i,A,s) for (int i = A[s] ; i != s ; i = A[i])

int ans[maxm],flag;
struct DancingLinks {
	int R[maxm] , L[maxm] , U[maxm] , D[maxm] , col[maxm] , row[maxm];
	int S[maxn]; bool hash[maxn];
	int pre , first , sz , NV;
	void init(int n) {
		for ( int i = 0 ; i <= n ; i ++ ) {
			U[i] = i, D[i] = i, S[i] = 0;
			L[i] = i - 1, R[i] = i + 1;
		}
		NV = n , sz = n + 1 , pre = -1 , first = 0;
	}
	void insert(int i, int j) { i++,j++;
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
		return ret;
	}
	void dfs(int deep) 
    {
        if(R[0]==0) {flag=deep;return ;}
		int idx = R[0];
		for (int i = R[0] ; i != 0; i = R[i]) if ( S[i] < S[idx] ) idx = i;
		EXremove(idx);
		FF(i , D , idx) 
        {
            ans[deep]=row[i]; 
			FF(j , R , i) EXremove(col[j]);
            dfs(deep+1); 
            if(flag) return ;
			FF(j , L , i) EXresume(col[j]);
		}
		EXresume(idx);
	}
}dlx;
char s[16][32];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T=0;
    while(scanf("%s",s[0])==1)
    {
         for(int i=1;i<N;i++) scanf("%s",s[i]);
         dlx.init(4*N*N);
         for(int i=0;i<N;i++)
             for(int j=0;j<N;j++)
             {
                  int l=0,r=N;
                  if(s[i][j]!='-') l=s[i][j]-'A',r=l+1;
                  for(int k=l;k<r;k++)
                  {
                       int rowid=i*N*N+j*N+k;
                       dlx.insert(rowid,0*N*N+i*N+k);
                       dlx.insert(rowid,1*N*N+j*N+k);
                       int gr=i/4,gc=j/4,gid=gr*4+gc;
                       dlx.insert(rowid,2*N*N+gid*N+k);
                       dlx.insert(rowid,3*N*N+i*N+j);
                  }
             }
         dlx.finish();
         flag=0;
         dlx.dfs(0);
         for(int i=0;i<flag;i++) 
         {
              ans[i]--;   
              int r=ans[i]/N/N,c=ans[i]/N%N,k=ans[i]%N;
              s[r][c]=k+'A';         
         }
         if(T++) puts("");
         for(int i=0;i<N;i++) printf("%s\n",s[i]);
    }
}
