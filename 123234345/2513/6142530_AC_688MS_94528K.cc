#include<stdio.h>
#include<string.h>
const int N=5000001;
int pre[N],num[N];
void init()
{
     for(int i=0;i<N;i++) pre[i]=i,num[i]=0;
}
int find(int x)
{
    int r=x;
    while(pre[r]!=r) r=pre[r];
    while(r!=x)
    {
        int t=pre[x];
        pre[x]=r;
        x=t;
    }
    return r;    
}
void Un(int x,int y)
{
     pre[find(y)]=find(x);
}
struct Trie
{
       int id;
       Trie *next[26];
};
Trie *s,*t,node[N],head;
int pos,id;
void build(Trie &head)
{
     head.id=-1;
     id=0;
     memset(head.next,0,sizeof(head.next));
}
int insert(char *str)
{
    s=&head; 
    int len=strlen(str),i;
    for(i=0;i<len;i++)
    {
            if(s->next[str[i]-'a']==0) break;
            s=s->next[str[i]-'a'];
    }
    for(int j=i;j<len;j++)
    {
            t=&node[pos++];
            memset(t->next,0,sizeof(t->next));
            t->id=-1;
            s->next[str[j]-'a']=t;
            s=t;
    }
    if(s->id==-1) s->id=id++;
    return s->id;
}
bool conn()
{
     int root=find(0);
     for(int i=1;i<id;i++)
        if(find(i)!=root) return 0;
     return 1;
}
bool eular()
{
     int cnt=0;
     for(int i=0;i<id;i++)
         if(num[i]&1) cnt++;
     return cnt<=2;
}
int main()
{
    
    char s1[11],s2[11];
    pos=0;
    init(),build(head);
    int x=0,y=0;
    while(scanf("%s%s",s1,s2)!=EOF)
    {
          x=insert(s1),y=insert(s2);
          num[x]++,num[y]++;
          Un(x,y);
    }
    puts(conn()&&eular()?"Possible":"Impossible");
}
