#include<stdio.h>
#include<string.h>
const int N=256;
int trie[61*1000][N],len;
void insert(char s[])
{
     int p=0;
     for(int i=0;s[i];i++)
     {
          if(trie[p][s[i]]==0) trie[p][s[i]]=len++;
          p=trie[p][s[i]];
     }
}
bool is_prefix(char s[])
{
     int p=0;
     for(int i=0;s[i];i++)
     {
           if(trie[p][s[i]]==0) return false;
           p=trie[p][s[i]];
     }
     return true;
}
int n1,n2;
int main()
{
    while(scanf("%d%d",&n1,&n2)==2)
    {
         getchar();
         len=1;
         memset(trie[0],0,sizeof(trie[0]));
         for(int i=0;i<n1;i++)
         {
             char s[N];
             gets(s);
             insert(s);
         }
         int ans=0;
         for(int i=0;i<n2;i++)
         {
              char s[N];
              gets(s);
              ans+=is_prefix(s);
         }
         printf("%d\n",ans);
    }
}
