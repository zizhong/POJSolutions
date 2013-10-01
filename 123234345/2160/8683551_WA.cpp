#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int N = 8;
struct Node
{
       int x,y;
       void read()
       {
            scanf("%d%d",&x,&y);
            if(x>y) swap(x,y);
       }
}rec[N];
bool cmp(const Node &a,const Node &b)
{
     if(a.x != b.x) return a.x<b.x;
     return a.y<b.y;
}
int main()
{
    for(int i=0;i<6;i++) rec[i].read();
    sort(rec,rec+6,cmp);
    int flag=0;
    for(int i=0;i<3;i++)
    {
         if( rec[2*i+0].x!=rec[2*i+1].x || 
             rec[2*i+0].y!=rec[2*i+1].y )
             {flag=1;break;}
    }
    int len[4]={0};
    len[0]=rec[0].x,len[1]=rec[0].y,len[2]=rec[2].x,len[3]=rec[2].y;
    if(!flag)
    {
             int rf=0;
             for(int i=0;!rf&&i<4;i++)
                 for(int j=i+1;!rf&&j<4;j++)
                       if(len[i]==len[j])
                       {
                            rf=1;
                            len[i]=0;
                            len[j]=0;
                            int t=0;
                            for(int k=0;k<4;k++)
                                if(len[k])
                                {
                                    len[t++]=len[k];
                                }
                            if(len[0]>len[1]) swap(len[0],len[1]);
                            if(!(len[0]==rec[4].x&&len[1]==rec[4].y))
                                 flag=1;
                       }             
    }
    puts(flag?"IMPOSSIBLE":"POSSIBLE");
    system("pause");
}
