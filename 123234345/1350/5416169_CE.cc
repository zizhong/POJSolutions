#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp1(const void *a,const void *b)
{
    return *(char *)a-*(char *)b;
}
int cmp2(const void *a,const void *b)
{
    return *(char *)b-*(char *)a;
}
int pro(int k)
{
    char s[5];
    int big,small,r,n;
    sprintf(s,"%d",k);
    n=strlen(s);
    qsort(s,n,sizeof(char),cmp2);
    sscanf(s,"%d",&big);
    qsort(s,n,sizeof(char),cmp1);
    sscanf(s,"%d",&small);
    r=big-small;
    printf("%d-%d=%d\n",big,small,r);
    return r;
}
int main()
{
    char s[5];
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%s",s)&&s[0]!='-')
    {
        int i,k;
        printf("N=%s:\n",s);
        if(s[0]==s[1]&&s[0]==s[1]&&s[0]==s[3]||strlen(s)<4||strlen>4)
        {
           printf("No!!\n");
           continue;
        }
        sscanf(s,"%d",&k);
        for(i=1;k!=6174&&k!=0;i++)
           k=pro(k);
        printf("Ok!! %d times\n",i-1);
    }
}
