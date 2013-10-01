#include<stdio.h>
#include<string.h>
const int N=128;
int trie[N][N],len;
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
             char s[128];
             gets(s);
             insert(s);
         }
         int ans=0;
         for(int i=0;i<n2;i++)
         {
              char s[128];
              gets(s);
              ans+=is_prefix(s);
         }
         printf("%d\n",ans);
    }
}
