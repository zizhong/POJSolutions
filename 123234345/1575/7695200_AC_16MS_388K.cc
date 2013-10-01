#include<stdio.h>
#include<string.h>
int main()
{
    int vow[26]={0};
    vow['a'-'a']=vow['o'-'a']=vow['e'-'a']=vow['i'-'a']=vow['u'-'a']=1;
    char s[1001];
    while(scanf("%s",s),strcmp(s,"end"))
    {
          int n=strlen(s),flag=1;
          int sum=0;
          for(int i=0;i<n;i++)
          {
               sum+=vow[s[i]-'a'];
          }
          if(!sum) flag=0;
          for(int i=0;flag&&i<n;i++)
          {
               if(i-1>=0)
               {
                     if(s[i]==s[i-1]&&(s[i]!='e'&&s[i]!='o'))
                          flag=0;
               }
               if(i-2>=0)
               {
                      sum=vow[s[i]-'a']+vow[s[i-1]-'a']+vow[s[i-2]-'a'];
                      if(sum==0||sum==3) flag=0;
               }
          }
          printf("<%s> is %sacceptable.\n",s,flag?"":"not ");
    }
}
