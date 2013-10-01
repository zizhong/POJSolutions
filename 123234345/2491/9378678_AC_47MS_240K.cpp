#include<cstdio>
#include<cstring>
struct Road
{
     char s1[128],s2[128];
     int pre,post;
     void init()
     {
          scanf("%s%s",s1,s2);
          pre=post=-1;
     }
}road[350];
int main()
{
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++)
    {
          int n;
          scanf("%d",&n);
          n--;
          for(int i=0;i<n;i++) road[i].init();
          for(int i=0;i<n;i++)
              for(int j=0;j<n;j++)
                  if(strcmp(road[i].s2,road[j].s1)==0)
                  {
                         road[j].pre=i,
                         road[i].post=j;
                         break;
                  }
          
          for(int i=0;i<n;i++) if(road[i].pre==-1)
          {
                  printf("Scenario #%d:\n%s\n",tt,road[i].s1);
                  int p=i;
                  while(p!=-1)
                  {
                        puts(road[p].s2);
                        p=road[p].post;
                  }
                  puts("");
                  break;
          }
    }
}
