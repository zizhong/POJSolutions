#include<stdio.h>
#include<string.h>
const int N=10000;
struct Trie
{
       int mark;
       Trie *next[10];
}head,node[10*N];
int pos;
void build_trie()
{
     pos=0;
     memset(&head,0,sizeof(Trie));
}
int insert(char *s)
{
    Trie *st=&head;
    int i=0,n=strlen(s);
    for(;i<n;i++)
    {
        int key=s[i]-'0';
        if(st->mark) return 0;
        if(st->next[key]==0) break;
        st=st->next[key];
    }
    if(i==n) return 0;
    for(;i<n;i++)
    {
        Trie *nw=&node[pos++];
        memset(nw,0,sizeof(Trie));
        st->next[s[i]-'0']=nw;
        st=nw;
    }
    return st->mark=1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int n;
         scanf("%d",&n);
         char s[11];
         build_trie();
         gets(s);
         int flag=1;
         while(n--)
         {
               gets(s);
               if(flag) flag=insert(s);
         }
         puts(flag?"YES":"NO");
    }
}
