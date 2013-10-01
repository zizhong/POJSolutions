#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int step[6][10][720];
struct Node
{
       int pos,style;
       char s[8];
}q[6*10*720];
const char Start[]="123456";

const int fac[]={0, 1, 2, 6, 24, 120,720, 5040, 40320, 362880, 3628800,39916800 };
const int nn=6;
int Cantor(char *s)
{
    int ans=0;
    for(int i=0;i<nn;i++)
    {
        int tmp=0;
        for(int j=i+1;j<nn;j++) if(s[i]>s[j]) tmp++;
        ans+=tmp*fac[nn-i-1];
    }
    return ans;
}


void prebfs()
{
     int head=0,tail=0;
     Node cur;
     cur.pos=0;
     cur.style=0;
     strcpy(cur.s,Start);
     q[tail++]=cur;
     step[0][0][Cantor(cur.s)]=0;
     
     while(head!=tail)
     {
          cur=q[head++];
          int stp=step[cur.pos][cur.style][Cantor(cur.s)];
          Node nx;
          //left shift
          if(cur.pos>0 && step[cur.pos-1][cur.style][Cantor(cur.s)]==-1)
          {
                 step[cur.pos-1][cur.style][Cantor(cur.s)]=stp+1;
                 q[tail].pos=cur.pos-1;
                 q[tail].style=cur.style;
                 strcpy(q[tail++].s,cur.s);
          }
          //right shift
          if(cur.pos<5)
          {
               if(cur.style<5) nx.style= cur.pos==cur.style?cur.style+1:cur.style;
               else if(cur.style==5) nx.style=5;
               else 
               {
                    if(cur.style<9) nx.style= cur.pos==cur.style-6?cur.style+1:cur.style;
                    else if(cur.pos==3) nx.style=5;
                    else nx.style=9;
               }
               
               if(step[cur.pos+1][nx.style][Cantor(cur.s)]==-1)
               {
                     step[cur.pos+1][nx.style][Cantor(cur.s)]=stp+1;
                     q[tail].pos=cur.pos+1;
                     q[tail].style=nx.style;
                     strcpy(q[tail++].s,cur.s);
               }
          }
          //swap 1
          if(cur.pos>0)
          {
               strcpy(nx.s,cur.s);
               char t=nx.s[cur.pos];nx.s[cur.pos]=nx.s[0];nx.s[0]=t;
               if(step[cur.pos][cur.style][Cantor(nx.s)]==-1)
               {
                    step[cur.pos][cur.style][Cantor(nx.s)]=stp+1;
                    q[tail].pos=cur.pos;
                    q[tail].style=cur.style;
                    strcpy(q[tail++].s,nx.s);  
               }
          }
          //swap 6
          if(cur.pos<5)
          {
               strcpy(nx.s,cur.s);
               char t=nx.s[cur.pos];nx.s[cur.pos]=nx.s[5];nx.s[5]=t;
               nx.style=cur.style;
               if(cur.style<5) nx.style+=6;
               if(nx.style==10) nx.style=5;
               if(step[cur.pos][nx.style][Cantor(nx.s)]==-1)
               {
                    step[cur.pos][nx.style][Cantor(nx.s)]=stp+1;
                    q[tail].pos=cur.pos;
                    q[tail].style=nx.style;
                    strcpy(q[tail++].s,nx.s);  
               }
          }
     }
}

char s1[8],s2[8];

char per[720][8];
void gen_permutation()
{
     char t[8]="123456";
     int cnt=0;
     do
     {
          strcpy(per[cnt++],t);
     }while(next_permutation(t,t+6));
}
int _abs(int a){return a>0?a:-a;}
int main()
{
   
    memset(step,-1,sizeof(step));
    prebfs();
    gen_permutation();
    int bitch[10]={0x1,0x3,0x7,0xf,0x1f,0x3f,0x21,0x23,0x27,0x2f};
    while(scanf("%s%s",s1,s2)==2)
    {
         int ans=0x3fffffff;
         for(int k=0;k<720;k++)
         {
              char t[8];
              for(int i=0;i<6;i++)
                  t[i]=s1[per[k][i]-'1'];
              int chg=0;
              for(int i=0;i<6;i++) 
                  if(s2[i]!=t[i]) chg|=(1<<i);
              for(int i=0;i<6;i++)
                 for(int j=0;j<10;j++) if(step[i][j][k]!=-1&& (chg&bitch[j])== chg)
                 {
                      int tmp=step[i][j][k];
                      for(int h=0;h<6;h++) tmp+=_abs(s2[h]+0-t[h]);
                      if(tmp<ans)ans=tmp;                  }
         }
         printf("%d\n",ans);
    }
}
