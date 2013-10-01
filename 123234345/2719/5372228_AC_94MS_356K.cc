#include<stdio.h>
#include<string.h>
int nine[10]={1,9,81,729,6561,59049,531441,4782969,43046721,387420489};
int main()
{
    char oldnum[12];
    char s[12];
    while(scanf("%s",&oldnum)!=EOF&&oldnum[0]!='0')
    {
        int i,n=strlen(oldnum);
        strcpy(s,oldnum);
        for(i=0;i<n;i++)
        {
            if(oldnum[i]>'4') --oldnum[i];
        }
        int newnum=0;
        for(i=0;i<n;i++)
        {
             newnum+=(oldnum[i]-'0')*nine[n-i-1];
        }
        printf("%s: %d\n",s,newnum);
    }
}
