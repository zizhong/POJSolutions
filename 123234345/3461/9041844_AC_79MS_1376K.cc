#include<cstdio>
#include<cstring>
char w[10010],t[1000010];
int d[10010];
const int  MAXN=10010;

int kmp(){
    int fail[MAXN]={-1},i=0,j;
    int ans=0;
    for (j=1;w[j];j++){
        for (i=fail[j-1];i>=0&&w[i+1]!=w[j];i=fail[i]);
        fail[j]=(w[i+1]==w[j]?i+1:-1);
    }
    //for(int i=0;w[i];i++) printf("%d ",fail[i]);puts("");
    for (i=j=0;t[i];i++)
    {
        if (t[i]==w[j])
            j++;
        else if (j)
            j=fail[j-1]+1,i--;
        if(!w[j]) j=fail[j-1]+1,ans++;
    }
    return ans;
}

int main()
{
    int T;
    for(scanf("%d",&T),getchar();T--;)
    {
         gets(w);
         gets(t);
         printf("%d\n",kmp());
    }   
}
