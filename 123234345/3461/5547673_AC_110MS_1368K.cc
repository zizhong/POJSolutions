#include<stdio.h>
#include<string.h>
char s[1000005],t[1000005];
int fail[1000005];
int KMP(char *S,char *T)//S[]是文本串,T[]是模式串
{
int IS,IP,i=0,j;
int num=0;
fail[0]=-1;
IS=strlen(S);
IP=strlen(T);
for(j=1;j<IP;j++)
{
   for(i=fail[j-1];i>=0&&T[i+1]!=T[j];i=fail[i]);
   fail[j]=((T[i+1]==T[j])? i+1:-1);
}
for(i=j=0;i<IS&&j<IP;i++)
{
   if(S[i]==T[j])
    j++;
   else if(j)
    j=fail[j-1]+1,i--;
   //return j==IP? i-IP:-1;
   if(j==IP)
    num++,j=fail[j-1]+1;
}
   return num;
}
int main()
{
int n;
scanf("%d",&n);
while(n--)
{
   scanf("%s",t);
   scanf("%s",s);
   printf("%d\n",KMP(s,t));
}
return 0;
}



