#include <iostream>
using namespace std;
int n, m, x, y;
bool d[15][15];
int v[15], f[10000][15][15];
long long ways[10000][15][15];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("key.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(d, false, sizeof(d));
        memset(f, -1, sizeof(f));
        memset(ways, 0, sizeof(ways));
        for (int i = 0; i < n; i++) cin>>v[i];
        for (int i = 0; i < m; i++){
            cin>>x>>y;
            d[x - 1][y - 1] = d[y - 1][x - 1] = true;
        }
        int s = 1 << n;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        if (i != j && d[i][j]){
            f[(1 << i) | (1 << j)][i][j] = v[i] + v[j] + v[i] * v[j];
            ways[(1 << i) | (1 << j)][i][j] = 1;
        }
        for (int p = 3; p < s; p++) for (int i = 0; i < n; i++)
            if (p & (1 << i)) for (int j = 0; j < n; j++)
            if (i != j && (p & (1 << j)) && f[p][i][j] != -1)
            for (int k = 0; k < n; k++) if ((p & (1 << k)) == 0 && d[j][k]){
                int q, r = p | (1 << k);
                if (d[i][k]) q = f[p][i][j] + v[k] + v[j] * v[k] + v[i] * v[j] * v[k];
                else q = f[p][i][j] + v[k] + v[j] * v[k];
                if (q > f[r][j][k]){
                    f[r][j][k] = q;
                    ways[r][j][k] = ways[p][i][j];
                }else if (q == f[r][j][k]) ways[r][j][k] += ways[p][i][j];
            }
        int ans = 0;
        long long way;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
            if (ans < f[s - 1][i][j]){
                ans = f[s - 1][i][j];
                way = ways[s - 1][i][j];
            }else if (ans == f[s - 1][i][j]) way += ways[s - 1][i][j];
        }
        if (n == 1) cout<<v[0]<<" 1"<<endl;
        else if (ans) cout<<ans<<" "<<(way >> 1)<<endl;
        else cout<<"0 0"<<endl;
    }
    return 0;
}
