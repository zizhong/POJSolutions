#include<cstdio>
#include<cstring>
const int N=9*7*7*7*7,M=365*N;
bool exist[365][9][7][7][7][7];
int mark[365];
int n;
int cover[9][4],exp[9][5];
int q[M],head,tail;
void prepro()
{
     int map[4][4];
     for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
           map[i][j]=4*i+j;
     for(int i=0;i<3;i++)
         for(int j=0;j<3;j++)
             for(int k=0;k<4;k++)
                 cover[i*3+j][k]=map[i+k/2][j+k%2];
     for(int i=0;i<3;i++)
         for(int j=0;j<3;j++)
         {
              int tmp=0;
              for(int k=0;k<3;k++)
              {
                   if(k!=i) exp[i*3+j][tmp++]=k*3+j;
                   if(k!=j) exp[i*3+j][tmp++]=i*3+k; 
              }
              exp[i*3+j][tmp++]=i*3+j;
         }
}
const int W=1<<16;
int code(int n,int pos,int c0,int c1,int c2,int c3)
{
    int ret=c0;
    ret|=(c1<<3);
    ret|=(c2<<6);
    ret|=(c3<<9);
    ret|=(pos<<12);
    return W*n+ret;
}
void decode(int p,int &n,int &pos,int &c0,int &c1,int &c2,int &c3)
{
     n=p/W,p%=W;
     c0=p&0x7,p>>=3;
     c1=p&0x7,p>>=3;
     c2=p&0x7,p>>=3;
     c3=p&0x7,p>>=3;
     pos=p;
     
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    prepro();
    while(scanf("%d",&n),n)
    {
         memset(exist,0,sizeof(bool)*N*n);
         
         for(int i=0;i<n;i++)
         {
              mark[i]=0;
              for(int j=0;j<16;j++)
              {
                  int x;
                  scanf("%d",&x);
                  if(x) mark[i]|=(1<<j);
              }
         }
         if((mark[0]&(1<<cover[4][0])) || 
            (mark[0]&(1<<cover[4][1])) ||
            (mark[0]&(1<<cover[4][2])) ||
            (mark[0]&(1<<cover[4][3])) )
            {puts("0");continue;}
         head=tail=0;
         int flag=1;
         q[tail++]=code(0,4,6,6,6,6);
         exist[0][4][6][6][6][6]=1;
         while(flag && head!=tail)
         {
              int cur=q[head++];
              head%=M;
              int cn,cpos,c0,c1,c2,c3;
              decode(cur,cn,cpos,c0,c1,c2,c3);
              if(cn==n-1){flag=0;break;}
              for(int k=0;k<5;k++)
              {
                    int nn=cn+1,npos=exp[cpos][k],n0=c0-1,n1=c1-1,n2=c2-1,n3=c3-1;
                    if( (mark[nn] & (1<<cover[npos][0])) ||
                        (mark[nn] & (1<<cover[npos][1])) ||
                        (mark[nn] & (1<<cover[npos][2])) ||
                        (mark[nn] & (1<<cover[npos][3])) )
                        continue;
                    switch(npos)
                    {
                         case 0:n0=7;break;
                         case 2:n1=7;break;
                         case 6:n2=7;break;
                         case 8:n3=7;break;
                    }
                    if(n0==0||n1==0||n2==0||n3==0) continue;
                    int ns=code(nn,npos,n0,n1,n2,n3);
                    if(exist[nn][npos][n0][n1][n2][n3]) continue;
                    exist[nn][npos][n0][n1][n2][n3]=1;
                    q[tail++]=ns;
                    tail%=M;
              }
         }
         printf("%d\n",!flag);
    }
}
