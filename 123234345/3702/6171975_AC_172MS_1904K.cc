#include<stdio.h>
#include<string.h>
#define clr(x) memset((x),0,sizeof(x))
const int N=35,M=2000000;
struct Node
{
       int chess[4];
       bool operator == (Node t)
            {return chess[0]==t.chess[0]&&chess[1]==t.chess[1]&&chess[2]==t.chess[2]&&chess[3]==t.chess[3];}
}q[M],sb,se;
bool visit[N][N][N][N];
char num[M];
bool vstd(Node *n)
{
     return visit[n->chess[0]][n->chess[1]][n->chess[2]][n->chess[3]];
}
void vst(Node *n)
{
     visit[n->chess[0]][n->chess[1]][n->chess[2]][n->chess[3]]=1;
}
int head,tail,star1,star2;
int x[4];
void ACT1(Node n)
{
     Node nk=n; 
     if(!n.chess[x[0]]||n.chess[x[2]]==0||num[head-1]<star2) return ;
     n.chess[x[0]]--,n.chess[x[3]]++;
     n.chess[x[1]]++,n.chess[x[2]]--;
     if(!vstd(&n))
     {
         vst(&n);
         num[tail]=num[head-1];
         q[tail++]=n;
     }
}
void ACT2(Node n)
{
     if(n.chess[x[0]]==0||n.chess[x[1]]==0||star2>=num[head-1]) return ;
     n.chess[x[0]]--,n.chess[x[2]]++;
     n.chess[x[1]]--;
     if(!vstd(&n))
     {
          vst(&n);
          num[tail]=num[head-1]-1;
          q[tail++]=n;
     }
}
void Solve()
{
     head=tail=0;
     num[tail]=star1;
     q[tail++]=sb;
     vst(&sb);
     while(head!=tail)
     {
           Node tn=q[head++];
           if(tn==se) {puts("YES");return ;}
           for(int i=0;i<4;i++)
           {
                   for(int j=0;j<4;j++) x[j]=(i+j)%4;
                   ACT1(tn);
                   ACT2(tn);
           }
     }
     puts("NO");
}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
              char s[31];
              gets(s),gets(s);
              star1=star2=0;
              clr(visit),clr(sb.chess),clr(se.chess);
              for(int i=0;s[i];i++)
                  if(s[i]=='*') sb.chess[i%4]++,star1++;
              gets(s);
              for(int i=0;s[i];i++)
                  if(s[i]=='*') se.chess[i%4]++,star2++;
              Solve();
    }
}
