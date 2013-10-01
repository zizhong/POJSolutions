#include<cstdio>
#include<cstring>
const int N=4010,M=210;
char s[N][M];
char ans[M];
int n,len;
bool exist(char w[],int x)
{
     int fail[M]={-1},i=0,j;
     for(j=1;w[j];j++) 
     {
          for(i=fail[j-1];i>=0&&w[i+1]!=w[j];i=fail[i]);
          fail[j]=w[i+1]==w[j]?i+1:-1;
     }
     for(int k=1;k<n;k++)
     {
           int flag=0;
           for(i=j=0;s[k][i];i++)
           {
               if(s[k][i]==w[j]) j++;
               else if(j) j=fail[j-1]+1,i--;
               if(!w[j]) {flag=1;break;}
           }
           if(!flag) return false;
     }
     return true;
}
bool ok(int x)
{
     ans[0]=0;
     for(int i=0;i+x<=len;i++)
     {
          char tmp[N];
          strncpy(tmp,s[0]+i,x);
          tmp[x]=0;
          if(exist(tmp,x))
          {
               if(ans[0]==0) strcpy(ans,tmp),ans[x]=0;
               else if(strcmp(ans,tmp)>0) strcpy(ans,tmp);
          }
     }
     return ans[0]!=0;
}
int main()
{
  
    while(scanf("%d",&n),n)
    {
          for(int i=0;i<n;i++) scanf("%s",s[i]);
          len=strlen(s[0]);
          int l=0,r=len;
          for(int i=1;i<n;i++)
          {
               int tmp=strlen(s[i]);
               if(tmp<r) r=tmp;
          }
          ++r;
          while(l+1<r)
          {
               int mid=l+r>>1;
               if(ok(mid)) l=mid;
               else r=mid;
          }
          ok(l);
          printf("%s\n",l?ans:"IDENTITY LOST");
    }
}
