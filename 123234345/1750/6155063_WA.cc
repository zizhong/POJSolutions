#include<stdio.h>
#include<string.h>
int cmp(char *s1,char *s2)
{
    int ans=0;
    int len1=strlen(s1),len2=strlen(s2);
    int min=len1>len2?len2:len1;
    for(;ans<min;ans++) if(s1[ans]!=s2[ans]) break;
    return ans;
}
void PS(int n)
{
     while(n--) putchar('.');
}
int main()
{
    
    char pre[11]={0},cur[11];
    int w=0;
    while(gets(cur))
    {
          int k=cmp(cur,pre);
          if(k>w) w++;
          else w=k;
          PS(w);
          puts(cur);
          strcpy(pre,cur);
    }
}
