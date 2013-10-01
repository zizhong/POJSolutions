#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
char dict[1024][128];
int f[1024],len[1024];
int n;
char s[4];
int cmp(const void* p1,const void* p2)
{
     char* s1 = (char *)p1;
     char *s2 = (char *)p2;
     int len1=strlen(s1),len2=strlen(s2);
     if(len1!=len2) return len1-len2;
     return strcmp(s1,s2);
}
int main()
{
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++)    
         scanf("%s",dict[i]);
    qsort(dict,n,sizeof(dict[0]),cmp);     
    for(int i=0;i<n;i++) len[i]=strlen(dict[i]);
    memset(f,0,sizeof(f));
    for(int i=0;i<n;i++) if(strcmp(s,dict[i])==0)
           {f[i]=1;break;}
    for(int i=0;i<n;i++) if(f[i])
    {
            for(int j=i+1;i<n&&len[j]<=len[i]+1;j++)
                if(len[j]==len[i]+1)
                {
                      int flag=0;
                      for(int k=0,k2=0;k<len[j];k++,k2++)
                      {
                           if(dict[j][k]!=dict[i][k2])
                                 flag++,k2--;
                           if(flag>1) break;
                      }
                      if(flag==1) f[j]=1;
                }
    }
    int idx=n-1;
    while(!f[idx]) --idx;
    puts(dict[idx]);
    //scanf("%'d");
}
