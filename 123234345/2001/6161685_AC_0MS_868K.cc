#include<stdio.h>
#include<string.h>
const int N=1001;
int trie[N*21][26];
char s[N][21];
int numc[N*21][26];
int main()
{
        int pos=1,i=0;
    while(scanf("%s",s[i])!=EOF)
    {
          int len=strlen(s[i]);
          int k=0,bg=0,flag=0;
          while(k<len)
          {
              int key=s[i][k]-'a';
              if(!trie[bg][key]) trie[bg][key]=pos++,flag=1;
              numc[bg][key]++;
              if(k==len-1)
              {
                     trie[bg][key]=-trie[bg][key];
              }              
              bg=trie[bg][key];
              if(bg<0) bg=-bg;
              k++;
          }
          i++;         
    }
    int n=i;
    for(i=0;i<n;i++)
    {
          int sn=strlen(s[i]);
          for(int j=0;j<sn;j++) putchar(s[i][j]);
          putchar(' ');
          for(int j=0,bg=0;j<sn;j++)
          {
                 putchar(s[i][j]);
                 int key=s[i][j]-'a';
                 if(numc[bg][key]==1) break;
                 bg=trie[bg][key];
                 if(bg<0) bg=-bg;
          }
          puts("");
    }
    return 0;
}
