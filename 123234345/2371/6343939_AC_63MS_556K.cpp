#include<stdio.h>
#include<stdlib.h>
const int N=100001;
int d[N];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int n,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&d[i]);
    qsort(d,n,sizeof(d[0]),cmp);
    char s[5];
    gets(s);gets(s);
    scanf("%d",&k);
    while(k--)
    {
              int i;
              scanf("%d",&i);
              printf("%d\n",d[i-1]);
    }}
