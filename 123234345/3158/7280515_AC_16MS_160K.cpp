#include<stdio.h>
#include<string.h>
const int N=128;
int deal(char *s1,char *s2)
{    
    int n1=strlen(s1),n2=strlen(s2),s;
    for(s=0;s<=n1;s++)
    {
         int j;
         for(j=0;j<n2;j++)
            if(!(j+s>=n1||!(s1[j+s]=='2'&&s2[j]=='2'))) break;
         if(j>=n2) break;
    }
    return n1>n2+s?n1:n2+s;
}
int main()
{
    char s1[N],s2[N];
    scanf("%s%s",s1,s2);
    int ans=deal(s1,s2),ans2=deal(s2,s1);
    printf("%d\n",ans>ans2?ans2:ans);
    //scanf("%'d");
}
