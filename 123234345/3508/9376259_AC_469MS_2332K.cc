#include<cstdio>
#include<cstring>
const int N=1000010;
char org[N];
char num[N];
int main()
{
    int T=0;
    while(scanf("%s",org),!(org[0]=='0'&&org[1]==0))
    {
         int len=strlen(org);
         num[len]=0;
         num[len-1]=org[len-1];
         int cc=0;
         for(int i=len-2;i>=0;i--)
         {
               int cf=0;
               if(org[i]-cc<num[i+1]) cf=1,num[i]=10+org[i]-cc-num[i+1]+'0';
               else num[i]=org[i]-cc-num[i+1]+'0';
               cc=cf;
         }
         printf("%d. ",++T);
         if(num[0]=='0') puts("IMPOSSIBLE");
         else puts(num);
    }
}
