#include<cstdio>
#include<cstring>
const int N=65536*2;
int cover[N<<2],Xor[N<<2];
bool hash[N];
void Fxor(int i)
{
     if(cover[i]!=-1) cover[i]^=1;
     else Xor[i]^=1;
}
void PushDown(int i)
{
     if(cover[i]!=-1)
     {
          cover[i<<1]=cover[i<<1|1]=cover[i];
          Xor[i<<1]=Xor[i<<1|1]=0;
          cover[i]=-1;
     }
     if(Xor[i])
     {
          Fxor(i<<1),Fxor(i<<1|1);
          Xor[i]=0;
     }
}
void update(char op,int L,int R,int l,int r,int i)
{
     if(L<=l && r<=R)
     {
          if(op=='U') cover[i]=1,Xor[i]=0;
          else if(op=='D') cover[i]=0,Xor[i]=0;
          if(op=='C' ||  op=='S') Fxor(i);
          return ;
     }
     PushDown(i);
     int m=l+r>>1;
     if(L<=m) update(op,L,R,l,m,i<<1);
     else if(op=='I' ||op=='C') cover[i<<1]=0,Xor[i<<1]=0;
     if(m+1<=R) update(op,L,R,m+1,r,i<<1|1);
     else if(op=='I' ||op=='C') cover[i<<1|1]=0,Xor[i<<1|1]=0;
}
void query(int l,int r,int i)
{
     if(cover[i]==1)
     {
          for(int j=l;j<=r;j++) hash[j]=true;
          return ;
     }else if(cover[i]==0) return ;
     PushDown(i);
     int m=l+r>>1;
     query(l,m,i<<1);
     query(m+1,r,i<<1|1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char op,lc,rc;
    int l,r;
    while(~scanf("%c %c%d,%d%c\n",&op,&lc,&l,&r,&rc))
    {
         l<<=1,r<<=1;
         if(lc=='(') l++;
         if(rc==')') r--;
         if(l>r)
         {
             if(op=='I' ||op=='C') cover[1]=0,Xor[1]=0;
             continue;
         }
         update(op,l,r,0,N,1);
    }
    query(0,N,1);
    int flag=0,s=-1,e;
    for(int i=0;i<N;i++)
    {
         if(hash[i])
         {
             if(s==-1) s=i;
             e=i;
         }else if(s!=-1)
         {
              if(flag) putchar(' ');flag=1;
              printf("%c%d,%d%c",(s&1)?'(':'[',s>>1,e+1>>1,(e&1)?')':']');
              s=-1;
         }
    }
    puts(flag?"":"empty set");
}

