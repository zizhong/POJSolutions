#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=32,M=2704156,mod=4077731,Target=0x0399C0;
int seq[N];
int h[mod],lv[mod],lvl;
int q[M],head,total;
int pre[M],stp[M];
char op[M];
int hash(int x)
{
    int key=x*13%mod;
    while(lv[key]==lvl && h[key]!=x)
         key=(key+1)%mod;
    if(lv[key]==lvl) return -1;
    lv[key]=lvl,h[key]=x;
    return key;
}
const int clr[8][7]=
{
    {0 , 2, 6,11,15,20,22},
    {1,  3, 8,12,17,21,23},
    {10, 9, 8, 7, 6, 5, 4},
    {19,18,17,16,15,14,13},
    {23,21,17,12, 8, 3, 1},
    {22,20,15,11, 6, 2, 0},
    {13,14,15,16,17,18,19},
    {4 , 5, 6, 7, 8, 9,10}
};
int mask=0xFFFFFF;
int Rotate(int x,int k)
{
    int firstbit=(x>>clr[k][0])&1,bit2;
    for(int i=0;i<6;i++)
    {
         x&=(mask^(1<<clr[k][i]));
         x|=((x>>clr[k][i+1])&1)<<clr[k][i];
    }
    x&=(mask^(1<<clr[k][6]));
    x|=firstbit<<clr[k][6];
    return x;
}
int num[4];
bool cmp(const int a,const int b)
{
     return num[a]>num[b];
}
const int Mstep=20000;
int main()
{   
    while(scanf("%d",&seq[0]),seq[0])
    {
         for(int i=1;i<24;i++) scanf("%d",&seq[i]);
         int ansnum=0;
         char step[Mstep]="";
         char st[Mstep];
         int curstep=Mstep;
         int top=0;
         
         int key=0;
         for(int j=0;j<24;j++)
             if(seq[j]==1) key|=(1<<j);
         int keypos[8]={6,7,8,11,12,15,16,17};
         num[0]=num[1]=num[2]=num[3]=0;
         for(int i=0;i<8;i++) num[seq[keypos[i]]]++;
         int t[4]={1,2,3};
         sort(t,t+3,cmp);
         
         for(int i=0;i<3;i++)
         {
              int start=0;
              for(int j=0;j<24;j++)
                   if(seq[j]==t[i]) start|=(1<<j);
              lvl++;
              int head=0,tail=0;
              pre[0]=-1;
              q[tail++]=start;
              hash(start);
              stp[0]=0;
              int flag=0;
              while(head!=tail)
              {
                   int cur=q[head++];
                   if(stp[head-1]>curstep) break;
                   if(cur == Target) {flag=1;break;}
                   
                   for(int k=0;k<8;k++)
                   {
                        int nx=Rotate(cur,k);
                        if(hash(nx)==-1) continue;
                        q[tail]=nx;
                        pre[tail]=head-1;
                        stp[tail]=stp[head-1]+1;
                        op[tail++]=k+'A';
                   }
              }
              if(flag==0) continue;
              if(i==0)
              {
                   ansnum=t[0];
                   int p=head-1;
                   top=0;
                   while(pre[p]!=-1) st[top++]=op[p],p=pre[p];
                   int len=0;
                   while(top) step[len++]=st[--top];
                   step[len]=0; 
                   curstep=len;                 
              }
              else
              {
                   char tmp[Mstep]="";
                   int p=head-1;
                   top=0;
                   while(pre[p]!=-1) st[top++]=op[p],p=pre[p];
                   int len=0;
                   while(top) tmp[len++]=st[--top];
                   tmp[len]=0;
                   if(len<curstep ||(len == curstep && strcmp(step,tmp)>0))
                   {
                        ansnum=t[i];
                        strcpy(step,tmp);
                        step[len]=0;
                        curstep=len;
                   }
              }
         }
         printf("%s\n%d\n",curstep?step:"No moves needed",ansnum);
    }
}
