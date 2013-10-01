#include<cstdio>
#include<cstring>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         char s1[16],s2[16],s3[16];
         scanf("%s%s%s",s1,s2,s3);
         int n1=strlen(s1),n2=strlen(s2),n3=strlen(s3);
         int d[5];
         memset(d,0,sizeof(d));
         char hv[8];
         int cnt=0;
         for(int i=0;i<n1;i++)
         {
               int flag=0;
               for(int j=0;j<cnt;j++)
                  if(hv[j]==s1[i]) flag=1;
               if(!flag) hv[cnt++]=s1[i];
         }
         for(int i=0;i<n2;i++)
         {
               int flag=0;
               for(int j=0;j<cnt;j++)
                  if(hv[j]==s2[i]) flag=1;
               if(!flag) hv[cnt++]=s2[i];
         }
         for(int i=0;i<n3;i++)
         {
               int flag=0;
               for(int j=0;j<cnt;j++)
                  if(hv[j]==s3[i]) flag=1;
               if(!flag) hv[cnt++]=s3[i];
         }
         
         int num=1;
         for(int i=1;i<=cnt;i++) num*=10;
         int ans=0;
         for(int k=0;k<num;k++)
         {
              int d[8]={0};
              int x=k,j=0;
              while(x) d[j++]=x%10,x/=10;
              int dig[8]={0};
              for(int i=0;i<cnt;i++) dig[hv[i]]=d[i];
              int flag=0;
              for(int i=0;i<cnt;i++)
                 for(int j=i+1;j<cnt;j++)
                     if(d[j]==d[i]) flag=1;
              if(flag) continue;
              if(n1>1&&dig[s1[0]]==0 || n2>1&&dig[s2[0]]==0 || n3>1&&dig[s3[0]]==0 ) continue;
              long long a=0,b=0,c=0;
              for(int i=0;i<n1;i++) a=a*10+dig[s1[i]];
              for(int i=0;i<n2;i++) b=b*10+dig[s2[i]];
              for(int i=0;i<n3;i++) c=c*10+dig[s3[i]];
              if(a+b==c) ans++;
              if(a-b==c) ans++;
              if(a*b==c) ans++;
              if(b && a==c*b) ans++;
         }
         printf("%d\n",ans);
    }
}
