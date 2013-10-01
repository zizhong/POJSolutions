#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=101,M=26;
char s1[N],s2[N];
int f1[M],f2[M];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    scanf("%s%s",s1,s2);
    int n=strlen(s1);
    for(int i=0;i<n;i++)
         f1[s1[i]-'A']++,f2[s2[i]-'A']++;
    qsort(f1,M,sizeof(f1[0]),cmp);
    qsort(f2,M,sizeof(f2[0]),cmp);
    int flag=1;
    for(int i=0;i<M;i++)
       if(f1[i]!=f2[i]) flag=0;
       //printf("%d %d\n",f1[i],f2[i]);
    puts(flag?"YES":"NO");
}
