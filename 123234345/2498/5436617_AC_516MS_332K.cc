#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int f[10]={9,3,7,9,3,7,9,3,7,9};
char s[10];
void strrev1()
{
     int len=strlen(s);
     for(int i=0;i<len/2;i++)
     {
         char t=s[i];
         s[i]=s[len-1-i];
         s[len-i-1]=t;
     }     
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int ncase,t;
    scanf("%d",&ncase);
    t=ncase;
    while(t--)
    {
        printf("Scenario #%d:\n",ncase-t);
        scanf("%s",s);
        strrev1();
        int i,sum=0,j,len=strlen(s),mi;
        for(i=0;i<len;i++)
        {
            if(s[i]!='?') sum+=(s[i]-'0')*f[i];
            else mi=i;
        }
        
        int isum=0;
        for(i=0;i<=9;i++)
        {
            isum=sum+i*f[mi];
            if(isum%10==0) break;
        }
        s[mi]=i+'0';
        strrev1();
        printf("%s\n\n",s);
    }
}
