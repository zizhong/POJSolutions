#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int n, success[1010], failure[1010], leaves[1010];
bool worm[1010];
vector <int> tree[1010];
bool cmp(const int &a, const int &b){
    return (failure[a] + 2) * leaves[b] < (failure[b] + 2) * leaves[a];
}
void dp(int root){
    if (tree[root].empty()){
        leaves[root] = 1;
        return;
    }
    for (int i = 0; i < tree[root].size(); i++) dp(tree[root][i]);
    for (int i = 0; i < tree[root].size(); i++){
        leaves[root] += leaves[tree[root][i]];
        if (!worm[root]) failure[root] += failure[tree[root][i]] + 2;
    }
    
    int order[1010];
    for (int i = 0; i < tree[root].size(); i++) order[i] = tree[root][i];
    sort(order, order + tree[root].size(), cmp);
    for (int i = 0, k = 0; i < tree[root].size(); i++){
        success[root] += (k + 1) * leaves[order[i]] + success[order[i]];
        k += failure[order[i]] + 2;
    }
}
int main(){
    int x;
    char w;
    while(scanf("%d",&n), n){
        for(int i = 0; i < n; i++) tree[i].clear();
        memset(worm, false, sizeof(worm));
        memset(success, 0, sizeof(success));
        memset(failure, 0, sizeof(failure));
        memset(leaves, 0, sizeof(leaves));
        for (int i = 0; i < n; i++){
            scanf("%d %c",&x,&w);
            if (x != -1) tree[x - 1].push_back(i);
            if (w == 'Y') worm[i] = true;
        }
        dp(0);
        printf("%.4f\n",success[0]*1.0/leaves[0]);
    }
}
