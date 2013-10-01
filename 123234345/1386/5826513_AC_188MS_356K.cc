#include<stdio.h>
#include<string.h>
int pre[27];
int find(int x)
{
    int r=x;
    while(pre[r]>0) r=pre[r];
    while(x!=r)
    {
               int t=pre[x];
               pre[x]=r;
               x=t;
    }
    return r;
}
int Union(int a,int b)
{
    int ra=find(a),rb=find(b);
    int t1=pre[ra],t2=pre[rb];
    if(t1>t2) pre[ra]=rb,pre[rb]=t1+t2;
    else pre[rb]=ra,pre[ra]=t1+t2;
}
int main()
{
    int nt;
    scanf("%d",&nt);
    while(nt--)
    {
               int n;
               scanf("%d",&n);
               for(int i=1;i<=26;i++) pre[i]=-1;
               int din[27]={0},dout[27]={0};
               char s[1001];
               gets(s);
               for(int i=1;i<=n;i++)
               {
                       gets(s);
                       int len=strlen(s);
                       int a=s[0]-'a'+1,
                           b=s[len-1]-'a'+1;
                       dout[a]++;
                       din[b]++;
                       if(find(a)!=find(b)) Union(a,b);
               }
               
               int conn=1,root;
               int i=1;
               while(i<=26&&(din[i]+dout[i]==0)) ++i;
               root=find(i);
               for(;i<=26;i++)
                   if((din[i]+dout[i])&&find(i)!=root)
                   {
                         conn=0;
                         break;
                   }
                   
               if(conn==0) printf("The door cannot be opened.\n");
               else
               {
                   int cnt1=0,cnt2=0,cnt0=0;
                   for(i=1;i<=26;i++)
                   {
                          int x=din[i]-dout[i];
                          if(x==0) cnt0++;
                          else if(x==1) cnt1++;
                          else if(x==-1) cnt2++;
                   } 
                   if(!(cnt0==26||(cnt0==24&&cnt1==1&&cnt2==1))) printf("The door cannot be opened.\n");
                   else printf("Ordering is possible.\n");
               }
    }
}
