#include<cstdio>
#include<cstring>
char w[10010],t[1000010];
int d[10010];
void maked()
{
     d[0]=0;
     for(int i=0,j=0;w[i];d[i]=j,i++,j++)
        while(j>=0&&w[i]!=w[j]) j=d[j]-1;
     //for(int i=0;w[i];i++) printf("%d ",d[i]);puts("");
}
int kmp()
{
    int ret=0;
    for(int i=0,j=0;t[i];i++,j++)
    {
           while(j>=0&&w[j]!=t[i]) j=d[j]-1;
           if(!w[j+1]) ret++,j=d[j]-1;
           //printf("%d %d\n",i,j);
    }
    return ret;
}
int main()
{
    int T;
    for(scanf("%d",&T),getchar();T--;)
    {
         gets(w);
         gets(t);
         maked();
         printf("%d\n",kmp());
    }   
}
