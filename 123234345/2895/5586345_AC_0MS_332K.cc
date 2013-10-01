#include<stdio.h>
#include<string.h>
int pt[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int pk[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,len,sum=0,p,w;
        char s[1002];
        scanf("%d%d",&p,&w);
        gets(s),gets(s);
        len=strlen(s);
        if(s[0]==' ') sum=p;
        else sum=p*pt[s[0]-'A'];
        for(i=1;i<len;i++)
        {
            if(s[i]==' ') sum+=p;
            else
            {
                sum+=pt[s[i]-'A']*p;
                if(s[i-1]!=' '&&pk[s[i-1]-'A']==pk[s[i]-'A']) sum+=w;
            }
        }
        printf("%d\n",sum);
    }
}
