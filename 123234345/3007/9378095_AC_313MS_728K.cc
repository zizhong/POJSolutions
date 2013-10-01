#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char str[1024][128];
int cc;
void substr(char *s1,char *s2,int i,int j)
{
     int len=0;
     for(int x=i;x<=j;x++)
        s2[len++]=s1[x];
     s2[len]=0;
}
void str_reverse(char *s1)
{
     int len=strlen(s1);
     for(int i=0;i<len/2;i++)
         swap(s1[i],s1[len-1-i]);
}
void cat_str(char *ns,char *s1,char *s2)
{
     int len=0;
     for(int i=0;s1[i];i++) ns[len++]=s1[i];
     for(int i=0;s2[i];i++) ns[len++]=s2[i];
     ns[len]=0;
}
void insert_str(char *s1)
{
     int flag=0;
     for(int i=0;i<cc;i++)
         if(strcmp(s1,str[i])==0)
         {
               flag=1;
               break;
         }
     if(!flag) strcpy(str[cc++],s1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
          char s[128];
          cc=0;
          scanf("%s",s);
          strcpy(str[cc++],s);
          int len=strlen(s);
          for(int i=1;s[i];i++)
          {
               for(int k=1;k<=7;k++)
               {
                    char s1[128],s2[128];
                    substr(s,s1,0,i-1);
                    substr(s,s2,i,len-1);
                    char tmp[128];
                    if(k&1)
                    {
                          strcpy(tmp,s1);
                          strcpy(s1,s2);
                          strcpy(s2,tmp); 
                    }
                    if(k&2) str_reverse(s1);
                    if(k&4) str_reverse(s2);
                    cat_str(tmp,s1,s2);
                    insert_str(tmp);
               }
          }
          printf("%d\n",cc);
    }
}
