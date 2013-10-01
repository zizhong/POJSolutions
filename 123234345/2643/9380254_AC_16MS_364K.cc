#include<cstdio>
#include<cstring>
struct Cand
{
       char s1[128],s2[128];
       int num;
       void init(){gets(s1),gets(s2);num=0;}
}cand[22];
int main()
{
    int n,m;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++) cand[i].init();
    scanf("%d",&m);
    getchar();
    while(m--)
    {
         char bid[128];
         gets(bid);
         for(int i=0;i<n;i++) if(strcmp(bid,cand[i].s1)==0)
         {
               cand[i].num++;
         }
    }
    int max=-1,tie=0,tail;
    for(int i=0;i<n;i++)
    {
         if(cand[i].num>max) max=cand[i].num,tail=i,tie=0;
         else if(cand[i].num==max) tie=1;
    }
    puts(tie?"tie":cand[tail].s2);
}
