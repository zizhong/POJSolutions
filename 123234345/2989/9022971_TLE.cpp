#include<cstdio>
#include<cstring>
const int N=128,M=32,K=1024;
struct Clique
{
       int c[4];
       Clique(){c[0]=c[1]=c[2]=c[3]=0;}
       Clique(int i)
       {
             c[0]=c[1]=c[2]=c[3]=0;
             c[i/32]|=1<<(i%32);
       }  
       Clique intersect(const Clique&c2)
       {
            Clique tmp=c2;
            tmp.c[0]&=c[0];
            tmp.c[1]&=c[1];
            tmp.c[2]&=c[2];
            tmp.c[3]&=c[3];
            return tmp;
       }
       bool empty(){return c[0]+c[1]+c[2]+c[3]==0;}
       bool exist(int i)
       {
            return (c[i/32]>>(i%32))&1;
       }
       void insert(int i)
       {
            c[i/32]|=(1<<(i%32));
       }
       bool operator == (const Clique &c2)
       {
            return c[0]==c2.c[0] &&
                   c[1]==c2.c[1] &&
                   c[2]==c2.c[2] &&
                   c[3]==c2.c[3];
       }
}cliq2[K*2];
int n,m,g[N][N];
int main()
{
     
      while(scanf("%d%d",&n,&m)==2)
	  {
		  memset(g,0,sizeof(g));
		  for(int i=0;i<m;i++)
		  {
				int x,y;
				scanf("%d%d",&x,&y);
				g[x-1][y-1]=g[y-1][x-1]=1;
		  }
		  int cnt=0;
		  for(int i=0;i<n&&cnt<=1000;i++)
		  {
			   Clique cur(i);
			   int flag=0;
			   Clique con;
			   for(int j=0;j<n;j++)
					if(g[i][j])  con.c[j/32]|=(1<<(j%32));
			   for(int j=0;j<cnt;j++)
			   {
    	             if(cliq2[j].exist(i)) break;
					 else
					 {
					     Clique c2=con.intersect(cliq2[j]);
					     if(c2==cliq2[j]) cliq2[j].insert(i),flag=1;                        
					     else if(!c2.empty()) c2.insert(i),cliq2[cnt++]=c2,flag=1;
					 }
			   }
			   if(!flag) cliq2[cnt++]=cur;
		      int tmp[2048]={0};
		      for(int i=0;i<cnt;i++) if(tmp[i]==0)
		           for(int j=0;j<cnt;j++) if(i!=j)
                       if(cliq2[i].intersect(cliq2[j])==cliq2[j]) tmp[j]=1;
              int tot=0;
              for(int i=0;i<cnt;i++) if(!tmp[i])  cliq2[tot++]=cliq2[i];
              cnt=tot;
		  /*for(int i=0;i<cnt;i++,puts(""))
		      for(int j=0;j<n;j++) if(cliq2[i].exist(j))printf("%d ",j);puts("-------------");*/
		  }
		  if(cnt>1000) puts("Too many maximal sets of friends.") ;
		  else printf("%d\n",cnt);   
	  }   
}
